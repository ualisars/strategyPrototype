#include "UI/Town/Market/SP_MarketWidget.h"

USP_MarketWidget::USP_MarketWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_MarketWidget::NativeConstruct()
{
	Super::NativeConstruct();
	DisplayItems<USP_MarketWidget>(Town, &USP_MarketWidget::CreateMarketGoodsRow, this);
	DisplayItems<USP_MarketWidget>(Player, &USP_MarketWidget::CreatePlayerGoodsRow, this);
}

