#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_MarketWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_MarketWidget : public UUserWidget
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
};
