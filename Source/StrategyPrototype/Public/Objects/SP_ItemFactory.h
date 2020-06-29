#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_ItemFactory.generated.h"

UENUM(BlueprintType)
enum class SP_ItemCategory : uint8
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
		SP_ItemCategory Category;
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

	FSP_Item(FString Name, float Cost, SP_ItemCategory Category, SP_ItemOwner Owner)
		:Name(Name), Cost(Cost), Category(Category), Owner(Owner)
	{
		bEmpty = false;
	}

	FSP_Item(FString Name, float Cost, SP_ItemCategory Category, SP_ItemOwner Owner, bool Consumable, int NutritionalValue)
		:Name(Name), Cost(Cost), Category(Category), Owner(Owner), Consumable(Consumable), NutritionalValue(NutritionalValue), bEmpty(false) {}

	bool operator==(const FSP_Item& OtherItem) const
	{
		if (Name == OtherItem.Name && Cost == OtherItem.Cost && Category == OtherItem.Category)
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

UENUM(BlueprintType)
enum class SP_ItemType : uint8
{
	Apple,
	Axe,
	Bread,
	Copper,
	Helmet,
	Iron,
	Sword,
	Wood
};

UCLASS()
class STRATEGYPROTOTYPE_API USP_ItemFactory : public UObject
{
	GENERATED_BODY()

public:
	static FSP_Item CreateItem(SP_ItemType Type, SP_ItemOwner Owner);
};
