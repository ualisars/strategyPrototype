#include "UI/Main/SP_GameDateWidget.h"

USP_GameDateWidget::USP_GameDateWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_GameDateWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ASP_GameStateBase* CurrentGameState = Cast<ASP_GameStateBase>(UGameplayStatics::GetGameState(GetWorld())))
	{
		GameState = CurrentGameState;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get GameMode in GameDateWidget"));
	}
}

