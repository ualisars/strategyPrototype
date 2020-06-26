#include "UI/Inventory/SP_InventoryWidget.h"


USP_InventoryWidget::USP_InventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonClose->OnClicked.AddDynamic(this, &USP_InventoryWidget::HideWidget);
	DisplayPlayerUnits();
	DisplayItems<USP_InventoryWidget>(Player, &USP_InventoryWidget::CreateItemRow, this);
}

void USP_InventoryWidget::HideWidget()
{
	RemoveFromParent();
}

void USP_InventoryWidget::DisplayPlayerUnits()
{
	if (Player == nullptr)
		return;

	TArray<FSP_Unit*> Units = Player->Units;
		
	ScrollBoxUnits->ClearChildren();

	for (FSP_Unit* Unit : Units)
	{
		CreateInventoryUnitWidget(*Unit);
	}
}

