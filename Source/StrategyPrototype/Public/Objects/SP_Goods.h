#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_Goods.generated.h"

UENUM(BlueprintType)
enum class SP_ItemType : uint8
{
	Armory,
	Food,
	Jewelry,
	Resource,
	Weapon
};

UENUM(BlueprintType)
enum class SP_ItemOwner : uint8
{
	Player,
	Town
};

USTRUCT(BlueprintType)
struct FSP_Item
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Cost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		SP_ItemType Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		SP_ItemOwner Owner;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool Consumable = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int NutritionalValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bEmpty = true;

	FSP_Item() {}

	~FSP_Item() {}

	FSP_Item(FString Name, float Cost, SP_ItemType Type, SP_ItemOwner Owner)
		:Name(Name), Cost(Cost), Type(Type), Owner(Owner)
	{
		bEmpty = false;
	}

	FSP_Item(FString Name, float Cost, SP_ItemType Type, SP_ItemOwner Owner, bool Consumable, int NutritionalValue)
		:Name(Name), Cost(Cost), Type(Type), Owner(Owner), Consumable(Consumable), NutritionalValue(NutritionalValue), bEmpty(false) {}

	bool operator==(const FSP_Item& OtherItem) const
	{
		if (Name == OtherItem.Name && Cost == OtherItem.Cost && Type == OtherItem.Type)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SetOwner(SP_ItemOwner NewOwner)
	{
		Owner = NewOwner;
	}
};

UCLASS()
class STRATEGYPROTOTYPE_API USP_Goods : public UObject
{
	GENERATED_BODY()
	
};
