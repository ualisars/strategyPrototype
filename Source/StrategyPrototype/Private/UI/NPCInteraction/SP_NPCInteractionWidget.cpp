#include "UI/NPCInteraction/SP_NPCInteractionWidget.h"

void USP_NPCInteractionWidget::DisplayNPCTradeWidget()
{
	if (NPCTradeWidgetClass)
	{
		NPCTradeWidget = CreateWidget<USP_NPCTradeWidget>(GetWorld(), NPCTradeWidgetClass);
		if (NPCTradeWidget)
		{
			NPCTradeWidget->AddToViewport();
			RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to create NPCTradeWidget in NPCInteractionWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get NPCTradeWidgetClass in NPCInteractionWidget"));
	}
}

USP_NPCInteractionWidget::USP_NPCInteractionWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_NPCInteractionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonTrade->OnClicked.AddDynamic(this, &USP_NPCInteractionWidget::DisplayNPCTradeWidget);
}