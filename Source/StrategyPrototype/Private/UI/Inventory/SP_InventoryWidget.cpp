#include "UI/Inventory/SP_InventoryWidget.h"

void USP_InventoryWidget::SetPlayer()
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
			UE_LOG(LogTemp, Warning, TEXT("Unable to get Player Pawn in InventoryWidget"));
		}
	}
}

USP_InventoryWidget::USP_InventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{}

void USP_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetPlayer();
	ButtonClose->OnClicked.AddDynamic(this, &USP_InventoryWidget::HideWidget);
	DisplayPlayerUnits();
	DisplayPlayerInventory();
}

void USP_InventoryWidget::HideWidget()
{
	RemoveFromParent();
}

void USP_InventoryWidget::DisplayPlayerInventory()
{
	if (Player == nullptr)
		return;

	TArray<FSP_Item> PlayerGoods = Player->Goods;
	TArray<FSP_Item> GoodsInRow;
	int CurrentSlotsInRow = 0;

	ScrollBoxInventory->ClearChildren();

	for (int i = 0; i < Player->MAX_INVENTORY_SLOTS; ++i)
	{
		if (PlayerGoods.Num() != 0)
		{
			if (CurrentSlotsInRow < SlotsInRow)
			{
				FSP_Item LastItem = PlayerGoods.Pop();
				GoodsInRow.Add(LastItem);
				CurrentSlotsInRow++;
			}
			else
			{
				CreateItemRow(CurrentSlotsInRow, GoodsInRow);
				GoodsInRow.Empty();
				CurrentSlotsInRow = 0;
			}
		}
		else
		{
			if (CurrentSlotsInRow < SlotsInRow)
			{
				CurrentSlotsInRow++;
			}
			else
			{
				CreateItemRow(CurrentSlotsInRow, GoodsInRow);
				GoodsInRow.Empty();
				CurrentSlotsInRow = 0;
			}
		}
	}
}

void USP_InventoryWidget::DisplayPlayerUnits()
{
	if (Player == nullptr)
		return;

	TArray<FSP_Unit*> Units = Player->Units;
		
	ScrollBoxUnits->ClearChildren();

	for (FSP_Unit* Unit : Units)
	{
		CreateInventoryUnitWidget(*Unit);
	}
}

