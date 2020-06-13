// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "UI/SP_InGameInterface.h"
#include "UI/Inventory/SP_InventoryWidget.h"
#include "SP_HUD.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYPROTOTYPE_API ASP_HUD : public AHUD
{
	GENERATED_BODY()

public:

	ASP_HUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> InGameInterfaceClass;

private:
	USP_InventoryWidget* InventoryWidget;

	USP_InGameInterface* InGameInterfaceWidget;
};
