#include "UI/NPCInteraction/SP_NPCInteractionWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "SP_PlayerController.h"

void USP_NPCInteractionWidget::DisplayNPCTradeWidget()
{
	if (NPCTradeWidgetClass)
	{
		NPCTradeWidget = CreateWidget<USP_NPCTradeWidget>(GetWorld(), NPCTradeWidgetClass);
		if (NPCTradeWidget)
		{
			NPCTradeWidget->AddToViewport();
			RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to create NPCTradeWidget in NPCInteractionWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get NPCTradeWidgetClass in NPCInteractionWidget"));
	}
}

void USP_NPCInteractionWidget::AttackNPC()
{
	APlayerController* DefaultController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (ASP_PlayerController* PlayerController = Cast<ASP_PlayerController>(DefaultController))
	{
		ASP_Player* Player = PlayerController->GetPlayerPawn();
		Player->StartBattle(Player->CharacterToMove);
	}
}

USP_NPCInteractionWidget::USP_NPCInteractionWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_NPCInteractionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonTrade->OnClicked.AddDynamic(this, &USP_NPCInteractionWidget::DisplayNPCTradeWidget);
	ButtonAttack->OnClicked.AddDynamic(this, &USP_NPCInteractionWidget::AttackNPC);
}

void USP_NPCInteractionWidget::UpdateTradeGoods()
{
	if (NPCTradeWidget)
	{
		NPCTradeWidget->UpdateGoods();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot update trade goods as NPCTradeWidget is not valid"));
	}
}
