#include "UI/Town/SP_TownWidget.h"

void USP_TownWidget::HideTownWidget()
{
	ASP_PlayerController* PlayerController = Cast<ASP_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	RemoveFromParent();
	PlayerController->SetGameState(SP_GameState::Default);
	PlayerController->SetPause(false);
}

USP_TownWidget::USP_TownWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_TownWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonLeaveTown->OnClicked.AddDynamic(this, &USP_TownWidget::HideTownWidget);
}

void USP_TownWidget::DisplayMarketWidget()
{
	RemoveFromParent();
}

