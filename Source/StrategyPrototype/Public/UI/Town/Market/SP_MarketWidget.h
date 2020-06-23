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
	class UTextBlock* TestText;
	
};
