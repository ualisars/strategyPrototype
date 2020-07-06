#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "Components/ScrollBox.h"
#include "SP_GridItemWidget.generated.h"

class ASP_Town;
struct FSP_Item;
struct FSP_Unit;

UCLASS()
class STRATEGYPROTOTYPE_API USP_GridItemWidget : public UUserWidget
{
	GENERATED_BODY()

	void SetPlayerAndTown();

protected:
	ASP_Player* Player = nullptr;
	ASP_BaseCharacter* NPC = nullptr;
	ASP_Town* Town = nullptr;

public:
	USP_GridItemWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
	int SlotsInRow = 4;

	template<typename WidgetClass>
	void DisplayItems(AActor* GridItemActor, void(WidgetClass::*CreateItemRow)(int, const TArray<FSP_Item>&), WidgetClass* WidgetObject)
	{
		int MaxSlots;
		TArray<FSP_Item> Goods;

		if (Cast<ASP_Player>(GridItemActor))
		{
			Goods = Player->Goods;
			MaxSlots = Player->MAX_INVENTORY_SLOTS;
		}
		else if (Cast<ASP_BaseCharacter>(GridItemActor))
		{
			Goods = NPC->Goods;
			MaxSlots = NPC->MAX_INVENTORY_SLOTS;
		}
		else if(Cast<ASP_Town>(GridItemActor))
		{
			Goods = Town->Goods;
			MaxSlots = Town->MAX_MARKET_SLOTS;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to cast GridItemActor to class ASP_Town, ASP_Player, ASP_BaseCharacter"));
			return;
		}

		TArray<FSP_Item> GoodsInRow;
		int CurrentSlotsInRow = 0;
		int CurrentItemIndex = 0;

		for (int i = 0; i < MaxSlots; ++i)
		{
			if (CurrentItemIndex < Goods.Num())
			{
				if (CurrentSlotsInRow < SlotsInRow)
				{
					FSP_Item Item = Goods[CurrentItemIndex];
					GoodsInRow.Add(Item);
					CurrentSlotsInRow++;
					CurrentItemIndex++;
				}
				else
				{
					(WidgetObject->*CreateItemRow)(CurrentSlotsInRow, GoodsInRow);
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
					(WidgetObject->*CreateItemRow)(CurrentSlotsInRow, GoodsInRow);
					GoodsInRow.Empty();
					CurrentSlotsInRow = 0;
				}
			}
		}
	}
};
