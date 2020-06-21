#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "Objects/SP_Object.h"
#include "SP_InventoryUnitWidget.h"
#include "SP_InventoryWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_InventoryWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void HideWidget();
	
	ASP_Player* Player = nullptr;

	void SetPlayer();

public:
	USP_InventoryWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImageInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImageUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* ScrollBoxInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* ScrollBoxUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextClose;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> InventoryUnitWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
	int SlotsInRow = 4;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateInventoryUnitWidget(FSP_Unit Unit);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateItemRow(int CurrentSlotsInRow, const TArray<FSP_Item>& GoodsInRow);

	void DisplayPlayerInventory();

	void DisplayPlayerUnits();

};
