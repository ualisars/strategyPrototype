#include "UI/Inventory/SP_InventoryWidget.h"

USP_InventoryWidget::USP_InventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonClose->OnClicked.AddDynamic(this, &USP_InventoryWidget::HideWidget);
	DisplayPlayerUnits();
}

void USP_InventoryWidget::HideWidget()
{
	RemoveFromParent();
}

void USP_InventoryWidget::DisplayPlayerUnits()
{
	TArray<AActor*> PlayerActors;
	TArray<FSP_Unit*> Units;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", PlayerActors);

	if (PlayerActors.Num() > 0)
	{
		if (ASP_Player* Player = Cast<ASP_Player>(PlayerActors[0]))
		{
			Units = Player->Units;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get player pawn in InventoryWidget"));
			return;
		}
	}
	
	ScrollBoxUnits->ClearChildren();

	for (FSP_Unit* Unit : Units)
	{
		CreateInventoryUnitWidget(*Unit);
	}
}

