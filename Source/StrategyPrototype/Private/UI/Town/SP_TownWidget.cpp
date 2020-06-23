#include "UI/Town/SP_TownWidget.h"

USP_TownWidget::USP_TownWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_TownWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonLeaveTown->OnClicked.AddDynamic(this, &USP_TownWidget::RemoveFromParent);
}

void USP_TownWidget::DisplayMarketWidget()
{
	RemoveFromParent();
}

