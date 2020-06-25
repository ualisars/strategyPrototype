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
	AActor* HitActor = LeftMouseHitResult.Actor.Get();

	// move player if player is present and hit actor is not obstacle
	if (PlayerPawn != nullptr && Cast<ASP_Obstacle>(HitActor) == nullptr)
	{
		PlayerPawn->MoveToLocation(LeftMouseHitResult.Location);
		ASP_Town* ChosenTown = Cast<ASP_Town>(HitActor);
		if (ChosenTown != nullptr)
		{
			PlayerPawn->TownToMove = ChosenTown;
			PlayerPawn->Mode = SP_CharacterMode::GoingToTown;

			if (PlayerPawn->bOverlappingWithTown)
			{
				PlayerPawn->InteractWithTown();
			}
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
		ASP_Town* Town = PlayerPawn->TownToMove;

		// Player buys goods

		/*
		if (Cast<ASP_Town>(DraggedItem.Owner) && Cast<ASP_Player>(DroppedItem.Owner))
		{
			PlayerPawn->AddItem(DraggedItem);
			Town->RemoveItem(DraggedItem);
		}
		// Player sells goods
		else if (Cast<ASP_Player>(DraggedItem.Owner) && Cast<ASP_Town>(DroppedItem.Owner))
		{
			Town->AddItem(DraggedItem);
			PlayerPawn->RemoveItem(DraggedItem);
		}
		*/
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



