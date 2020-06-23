// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Common/SP_GridItemWidget.h"

void USP_GridItemWidget::SetPlayer()
{
	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", PlayerActors);

	if (PlayerActors.Num() > 0)
	{
		if (ASP_Player* PlayerPawn = Cast<ASP_Player>(PlayerActors[0]))
		{
			Player = PlayerPawn;
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
}

