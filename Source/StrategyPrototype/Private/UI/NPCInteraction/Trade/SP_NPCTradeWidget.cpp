#include "UI/NPCInteraction/Trade/SP_NPCTradeWidget.h"

USP_NPCTradeWidget::USP_NPCTradeWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_NPCTradeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateGoods();
}

void USP_NPCTradeWidget::UpdateGoods()
{
	ScrollBoxNPCGoods->ClearChildren();
	ScrollBoxPlayerGoods->ClearChildren();
	DisplayItems<USP_NPCTradeWidget>(NPC, &USP_NPCTradeWidget::CreateNPCGoodsRow, this);
	DisplayItems<USP_NPCTradeWidget>(Player, &USP_NPCTradeWidget::CreatePlayerGoodsRow, this);
}

