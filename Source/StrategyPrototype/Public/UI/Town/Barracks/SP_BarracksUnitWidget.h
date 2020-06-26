#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_BarracksUnitWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_BarracksUnitWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USP_BarracksUnitWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnitName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnitHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnitDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnitCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonAdd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextAdd;
};
