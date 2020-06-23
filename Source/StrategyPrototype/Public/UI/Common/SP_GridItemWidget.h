// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "Components/ScrollBox.h"
#include "SP_GridItemWidget.generated.h"

struct FSP_Item;
struct FSP_Unit;

UCLASS()
class STRATEGYPROTOTYPE_API USP_GridItemWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	ASP_Player* Player = nullptr;

	void SetPlayer();

public:

	USP_GridItemWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
	int SlotsInRow = 4;

	template<typename WidgetClass>
	void DisplayItems(UScrollBox* ScrollBox, void(WidgetClass::*CreateItemRow)(int, const TArray<FSP_Item>&), WidgetClass* WidgetObject)
	{
		if (Player == nullptr)
			return;

		TArray<FSP_Item> PlayerGoods = Player->Goods;
		TArray<FSP_Item> GoodsInRow;
		int CurrentSlotsInRow = 0;

		ScrollBox->ClearChildren();

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
