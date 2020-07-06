#include "UI/Common/SP_GridItemWidget.h"

void USP_GridItemWidget::SetPlayerAndTown()
{
	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", PlayerActors);

	if (PlayerActors.Num() > 0)
	{
		if (ASP_Player* PlayerPawn = Cast<ASP_Player>(PlayerActors[0]))
		{
			Player = PlayerPawn;
			if (PlayerPawn)
			{
				Town = PlayerPawn->TownToMove;
				NPC = PlayerPawn->CharacterToMove;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Player Pawn is nullptr in GridItemWidget"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get Player Pawn in GridItemWidget"));
		}
	}
}

USP_GridItemWidget::USP_GridItemWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_GridItemWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetPlayerAndTown();
}

