#include "UI/Main/SP_GameDateWidget.h"

USP_GameDateWidget::USP_GameDateWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_GameDateWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ASP_GameMode* CurrentGameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GameMode = CurrentGameMode;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get GameMode in GameDateWidget"));
	}
}

