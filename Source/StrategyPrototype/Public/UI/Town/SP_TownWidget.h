#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UI/Town/Barracks/SP_BarracksWidget.h"
#include "UI/Town/Market/SP_MarketWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SP_PlayerController.h"
#include "SP_TownWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_TownWidget : public UUserWidget
{
	GENERATED_BODY()

	USP_BarracksWidget* BarracksWidget;

	USP_MarketWidget* MarketWidget;

	UFUNCTION()
	void HideTownWidget();

	UFUNCTION()
	void DisplayBarracksWidget();

	UFUNCTION()
	void DisplayMarketWidget();

public:
	USP_TownWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonCastle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* ImageCastle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonBarracks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* ImageBarracks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonMarket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* ImageMarket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonLeaveTown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLeaveTown;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> BarracksWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> MarketWidgetClass;
};
