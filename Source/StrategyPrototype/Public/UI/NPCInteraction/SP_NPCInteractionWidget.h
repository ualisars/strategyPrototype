#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/NPCInteraction/Trade/SP_NPCTradeWidget.h"
#include "Components/Button.h"
#include "SP_NPCInteractionWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_NPCInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

	USP_NPCTradeWidget* NPCTradeWidget;

	UFUNCTION()
	void DisplayNPCTradeWidget();

	UFUNCTION()
	void AttackNPC();

public:
	USP_NPCInteractionWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonTrade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextTrade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonLeave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLeave;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> NPCTradeWidgetClass;

	UFUNCTION()
	void UpdateTradeGoods();
};
