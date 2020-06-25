#include "UI/SP_HUD.h"

ASP_HUD::ASP_HUD()
{
}

void ASP_HUD::DrawHUD()
{
	Super::DrawHUD();
}

void ASP_HUD::BeginPlay()
{
	Super::BeginPlay();
}

void ASP_HUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASP_HUD::DisplayInventory()
{
	if (InventoryWidgetClass)
	{
		InventoryWidget = CreateWidget<USP_InventoryWidget>(GetWorld(), InventoryWidgetClass);
	}
	if (InventoryWidget)
	{
		InventoryWidget->AddToViewport();
	}
}

void ASP_HUD::HideInventory()
{
	if (InventoryWidget)
	{
		InventoryWidget->RemoveFromParent();
	}
}
