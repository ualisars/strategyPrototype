#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UI/Common/SP_GridItemWidget.h"
#include "SP_InventoryUnitWidget.h"
#include "SP_InventoryWidget.generated.h"


UCLASS()
class STRATEGYPROTOTYPE_API USP_InventoryWidget : public USP_GridItemWidget
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void HideWidget();
	
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

	UFUNCTION(BlueprintImplementableEvent)
	void CreateInventoryUnitWidget(FSP_Unit Unit);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateItemRow(int CurrentSlotsInRow, const TArray<FSP_Item>& GoodsInRow);

	void DisplayPlayerUnits();

};
