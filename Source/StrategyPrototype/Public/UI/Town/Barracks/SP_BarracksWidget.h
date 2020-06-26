#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "SP_Town.h"
#include "SP_BarracksWidget.generated.h"

struct FSP_Unit;

UCLASS()
class STRATEGYPROTOTYPE_API USP_BarracksWidget : public UUserWidget
{
	GENERATED_BODY()

	ASP_Town* Town;

	void SetTown();

public:
	USP_BarracksWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBarracks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* ScrollBoxUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonLeave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLeave;

	UFUNCTION(BlueprintImplementableEvent)
	void AddBarracksUnitWidget(FSP_Unit Unit);
};
