// Fill out your copyright notice in the Description page of Project Settings.

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

	if (InventoryWidgetClass)
	{
		InGameInterfaceWidget = CreateWidget<USP_InGameInterface>(GetWorld(), InGameInterfaceClass);
		if (InGameInterfaceWidget)
		{
			InGameInterfaceWidget->AddToViewport();
		}
	}
}

void ASP_HUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
