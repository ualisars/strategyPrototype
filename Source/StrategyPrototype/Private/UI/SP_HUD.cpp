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
		if (InventoryWidget)
		{
			InventoryWidget->AddToViewport();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get InventoryWidgetClass in HUD"));
	}
}

void ASP_HUD::HideInventory()
{
	if (InventoryWidget)
	{
		InventoryWidget->RemoveFromParent();
	}
}

void ASP_HUD::DisplayNPCInteractionWidget()
{
	if (NPCInteractionWidgetClass)
	{
		NPCInteractionWidget = CreateWidget<USP_NPCInteractionWidget>(GetWorld(), NPCInteractionWidgetClass);
		if (NPCInteractionWidget)
		{
			NPCInteractionWidget->AddToViewport();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get NPCInteractionWidgetClass in HUD"));
	}
}

void ASP_HUD::HideNPCInteractionWidget()
{
	if (NPCInteractionWidget)
	{
		NPCInteractionWidget->RemoveFromParent();
	}
}

void ASP_HUD::DisplayTownWidget()
{
	if (TownWidgetClass)
	{
		TownWidget = CreateWidget<USP_TownWidget>(GetWorld(), TownWidgetClass);
		if (TownWidget)
		{

			TownWidget->AddToViewport();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get TownWidgetClass in HUD"));
	}
}

void ASP_HUD::UpdateTownMarket()
{
	if (TownWidget)
	{
		TownWidget->UpdateMarket();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TownWidget is not specified in HUD"));
	}
}

void ASP_HUD::UpdateNPCTradeGoods()
{
	if (NPCInteractionWidget)
	{
		NPCInteractionWidget->UpdateTradeGoods();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NPCInteractionWidget is not specified in HUD"));
	}
}
