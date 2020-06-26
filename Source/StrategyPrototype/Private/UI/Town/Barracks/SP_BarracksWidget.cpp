#include "UI/Town/Barracks/SP_BarracksWidget.h"

void USP_BarracksWidget::SetTown()
{
	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", PlayerActors);

	if (PlayerActors.Num() > 0)
	{
		if (ASP_Player* PlayerPawn = Cast<ASP_Player>(PlayerActors[0]))
		{
			Town = PlayerPawn->TownToMove;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get Player Pawn in BarracksWidget"));
		}
	}
}

USP_BarracksWidget::USP_BarracksWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_BarracksWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonLeave->OnClicked.AddDynamic(this, &USP_BarracksWidget::RemoveFromParent);
	
	SetTown();

	TArray<FSP_Unit> Units = Town->AvailableUnits;

	if (Town)
	{
		for (FSP_Unit Unit : Units)
		{
			AddBarracksUnitWidget(Unit);
		}
	}
}

