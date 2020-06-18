#include "UI/Inventory/SP_InventoryWidget.h"

USP_InventoryWidget::USP_InventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonClose->OnClicked.AddDynamic(this, &USP_InventoryWidget::HideWidget);
}

void USP_InventoryWidget::HideWidget()
{
	RemoveFromParent();
}

