#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_MainInterfaceWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_MainInterfaceWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USP_MainInterfaceWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UWrapBox* PlayerStatsBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UWrapBox* GameDateBox;
};
