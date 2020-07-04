#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "UI/Inventory/SP_InventoryWidget.h"
#include "UI/NPCInteraction/SP_NPCInteractionWidget.h"
#include "UI/Town/SP_TownWidget.h"
#include "SP_HUD.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_HUD : public AHUD
{
	GENERATED_BODY()

	USP_InventoryWidget* InventoryWidget;

	USP_TownWidget* TownWidget;

	USP_NPCInteractionWidget* NPCInteractionWidget;

public:

	ASP_HUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> TownWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> NPCInteractionWidgetClass;

	UFUNCTION(BlueprintCallable)
	void DisplayInventory();

	UFUNCTION(BlueprintCallable)
	void HideInventory();

	UFUNCTION(BlueprintCallable)
	void DisplayNPCInteractionWidget();

	UFUNCTION(BlueprintCallable)
	void HideNPCInteractionWidget();

	UFUNCTION(BlueprintCallable)
	void DisplayTownWidget();

	UFUNCTION()
	void UpdateTownMarket();
};
