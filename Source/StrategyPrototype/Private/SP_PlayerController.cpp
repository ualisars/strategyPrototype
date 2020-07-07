// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_PlayerController.h"

#define CollisionQueryDefault EObjectTypeQuery::ObjectTypeQuery1
#define CollisionQueryBlockAllDynamic EObjectTypeQuery::ObjectTypeQuery6
#define CollisionQueryOverlapAllDynamic EObjectTypeQuery::ObjectTypeQuery7

ASP_PlayerController::ASP_PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ASP_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<ASP_HUD>(GetHUD());
	if (HUD == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("Failed to cast HUD to SP_HUD"));
}

void ASP_PlayerController::FindPlayerPawn()
{
	if (PlayerPawn != nullptr)
		return;

	TSubclassOf<ASP_Player> ClassToFind;
	ClassToFind = ASP_Player::StaticClass();
	TArray<AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundPlayers);
	if (FoundPlayers.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No player pawn found"));
		return;
	}

	PlayerPawn = Cast<ASP_Player>(FoundPlayers[0]);
	if (PlayerPawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to cast AActor to SP_Player in PlayerController"));
	}
}

void ASP_PlayerController::PlayerNPCBuySellItem(FSP_Item DraggedItem, FSP_Item DroppedItem)
{
	if (ASP_BaseCharacter* NPC = PlayerPawn->CharacterToMove)
	{
		// Player buys goods
		if (DraggedItem.Owner == SP_ItemOwner::NPC && DroppedItem.Owner == SP_ItemOwner::Player)
		{
			PlayerPawn->AddItem(DraggedItem);
			NPC->RemoveItem(DraggedItem);
		}
		// Player sells goods
		else if (DraggedItem.Owner == SP_ItemOwner::Player && DroppedItem.Owner == SP_ItemOwner::NPC)
		{
			NPC->AddItem(DraggedItem);
			PlayerPawn->RemoveItem(DraggedItem);
		}

		HUD->UpdateNPCTradeGoods();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to buy or sell goods as CharacterToMove is nullptr"));
	}
}

void ASP_PlayerController::PlayerTownBuySellItem(FSP_Item DraggedItem, FSP_Item DroppedItem)
{
	if (ASP_Town* Town = PlayerPawn->TownToMove)
	{
		// Player buys goods
		if (DraggedItem.Owner == SP_ItemOwner::Town && DroppedItem.Owner == SP_ItemOwner::Player)
		{
			PlayerPawn->AddItem(DraggedItem);
			Town->RemoveItem(DraggedItem);
		}

		// Player sells goods
		else if (DraggedItem.Owner == SP_ItemOwner::Player && DroppedItem.Owner == SP_ItemOwner::Town)
		{
			Town->AddItem(DraggedItem);
			PlayerPawn->RemoveItem(DraggedItem);
		}

		HUD->UpdateTownMarket();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to buy or sell goods as TownToMove is nullptr"));
	}
}

void ASP_PlayerController::LeftMousePressed()
{
	FHitResult LeftMouseHitResult;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = 
	{ 
		TEnumAsByte<EObjectTypeQuery>(CollisionQueryDefault),
		TEnumAsByte<EObjectTypeQuery>(CollisionQueryBlockAllDynamic),
		TEnumAsByte<EObjectTypeQuery>(CollisionQueryOverlapAllDynamic)
	};

	GetHitResultUnderCursorForObjects(ObjectTypes, false, LeftMouseHitResult);
	UE_LOG(LogTemp, Warning, TEXT("X: %f, Y: %f, Z: %f"), LeftMouseHitResult.Location.X, LeftMouseHitResult.Location.Y, LeftMouseHitResult.Location.Z);

	FindPlayerPawn();

	PlayerPawn->TownToMove = nullptr;
	PlayerPawn->CharacterToMove = nullptr;

	AActor* HitActor = LeftMouseHitResult.Actor.Get();

	// move player if player is present and hit actor is not obstacle
	if (PlayerPawn != nullptr && Cast<ASP_Obstacle>(HitActor) == nullptr)
	{
		PlayerPawn->MoveToLocation(LeftMouseHitResult.Location);
		ASP_Town* ChosenTown = Cast<ASP_Town>(HitActor);

		// character was hit, so move player to another character
		if (ASP_BaseCharacter* HitCharacter = Cast<ASP_BaseCharacter>(HitActor))
		{
			PlayerPawn->CharacterToMove = HitCharacter;
			PlayerPawn->SetMode(SP_CharacterMode::GoingToCharacter);
			PlayerPawn->MoveToCharacter(HitCharacter);

			if (PlayerPawn->OverlappingCharacter == HitCharacter)
			{
				PlayerPawn->InteractWithCharacter();
			}
		}

		// town was hit, so move player to a town
		else if (ASP_Town* ChosenTown = Cast<ASP_Town>(HitActor))
		{
			PlayerPawn->TownToMove = ChosenTown;
			PlayerPawn->SetMode(SP_CharacterMode::GoingToTown);

			if (PlayerPawn->OverlappingTown && PlayerPawn->OverlappingTown->Name == ChosenTown->Name)
			{
				PlayerPawn->InteractWithTown();
				return;
			}
			PlayerPawn->MoveToLocation(LeftMouseHitResult.Location);
		}

		// no actors was hit, so move to location
		else
		{
			PlayerPawn->SetMode(SP_CharacterMode::Roaming);
			PlayerPawn->MoveToLocation(LeftMouseHitResult.Location);
		}
	}
}

void ASP_PlayerController::RightMousePressed()
{
}

void ASP_PlayerController::SetInputModeToGameOnly()
{
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(false);
	SetInputMode(InputMode);
}

void ASP_PlayerController::BuySellItem(FSP_Item DraggedItem, FSP_Item DroppedItem)
{
	if (!DraggedItem.bEmpty && DroppedItem.bEmpty)
	{
		if (PlayerPawn->GetMode() == SP_CharacterMode::InteractingWithCharacter)
		{
			PlayerNPCBuySellItem(DraggedItem, DroppedItem);
		}
		else if (PlayerPawn->GetMode() == SP_CharacterMode::InteractingWithTown)
		{
			PlayerTownBuySellItem(DraggedItem, DroppedItem);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to buy or sell items: Incorrect Player mode"));
			return;
		}
	}
}

void ASP_PlayerController::OpenInventory()
{
	HUD->DisplayInventory();
	SetGameState(SP_GameState::Inventory);
	SetPause(true);
}

void ASP_PlayerController::CloseInventory()
{
	HUD->HideInventory();
	SetGameState(SP_GameState::Default);
	SetPause(false);
}

void ASP_PlayerController::DisplayNPCInteraction()
{
	HUD->DisplayNPCInteractionWidget();
	SetGameState(SP_GameState::Interaction);
	PlayerPawn->SetMode(SP_CharacterMode::InteractingWithCharacter);
	SetPause(true);
}

void ASP_PlayerController::HideDisplayInteraction()
{
	HUD->HideNPCInteractionWidget();
	SetGameState(SP_GameState::Default);
	PlayerPawn->SetMode(SP_CharacterMode::Roaming);
	SetPause(false);
}

void ASP_PlayerController::SetGameState(SP_GameState NewGameState)
{
	if (GameState == SP_GameState::Default)
	{
		GameState = NewGameState;
	}
	else if (GameState != SP_GameState::Default && NewGameState == SP_GameState::Default)
	{
		GameState = NewGameState;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Improper transition to new game state"))
	}
}

SP_GameState ASP_PlayerController::GetGameState() const
{
	return GameState;
}

void ASP_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ASP_PlayerController::LeftMousePressed);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ASP_PlayerController::RightMousePressed);
}



