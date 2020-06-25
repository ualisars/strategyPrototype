#include "UI/Town/SP_TownWidget.h"

void USP_TownWidget::HideTownWidget()
{
	ASP_PlayerController* PlayerController = Cast<ASP_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	RemoveFromParent();
	PlayerController->SetGameState(SP_GameState::Default);
	PlayerController->SetPause(false);
}

void USP_TownWidget::DisplayBarracksWidget()
{
	if (BarracksWidgetClass)
	{
		BarracksWidget = CreateWidget<USP_BarracksWidget>(GetWorld(), BarracksWidgetClass);
		if (BarracksWidget)
		{
			BarracksWidget->AddToViewport();
			RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to create BarracksWidget in TownWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get BarracksWidgetClass in TownWidget"));
	}
	
}

void USP_TownWidget::DisplayMarketWidget()
{
	if (MarketWidgetClass)
	{
		MarketWidget = CreateWidget<USP_MarketWidget>(GetWorld(), MarketWidgetClass);
		if (MarketWidget)
		{
			MarketWidget->AddToViewport();
			RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to create MarketWidget in TownWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get MarketWidgetClass in TownWidget"));
	}
}

USP_TownWidget::USP_TownWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_TownWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonLeaveTown->OnClicked.AddDynamic(this, &USP_TownWidget::HideTownWidget);
	ButtonBarracks->OnClicked.AddDynamic(this, &USP_TownWidget::DisplayBarracksWidget);
	ButtonMarket->OnClicked.AddDynamic(this, &USP_TownWidget::DisplayMarketWidget);
}



