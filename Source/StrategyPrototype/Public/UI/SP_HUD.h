#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "UI/Inventory/SP_InventoryWidget.h"
#include "UI/Town/SP_TownWidget.h"
#include "SP_HUD.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_HUD : public AHUD
{
	GENERATED_BODY()

	USP_InventoryWidget* InventoryWidget;

	USP_TownWidget* TownWidget;

public:

	ASP_HUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void DisplayInventory();

	UFUNCTION(BlueprintCallable)
	void HideInventory();

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> TownWidgetClass;

	UFUNCTION(BlueprintCallable)
	void DisplayTownWidget();

	UFUNCTION()
	void UpdateTownMarket();
};
