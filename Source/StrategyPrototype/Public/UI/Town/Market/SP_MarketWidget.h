#pragma once

#include "CoreMinimal.h"
#include "UI/Common//SP_GridItemWidget.h"
#include "SP_MarketWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_MarketWidget : public USP_GridItemWidget
{
	GENERATED_BODY()

public:
	USP_MarketWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* MarketGoodsBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* PlayerGoodsBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* ControlPanelBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* ScrollBoxMarketGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* ScrollBoxPlayerGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonLeave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLeave;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateMarketGoodsRow(int CurrentSlotsInRow, const TArray<FSP_Item>& GoodsInRow);

	UFUNCTION(BlueprintImplementableEvent)
	void CreatePlayerGoodsRow(int CurrentSlotsInRow, const TArray<FSP_Item>& GoodsInRow);
};
