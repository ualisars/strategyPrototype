#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"
#include "Templates/SharedPointer.h"
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
	NPC,
	Town
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
	Necklace,
	Wood
};

USTRUCT(BlueprintType)
struct FSP_Item
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	SP_ItemType Type;
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TWeakObjectPtr<UTexture2D> ItemTexture;

	FSP_Item() {}

	~FSP_Item() {}

	FSP_Item(FString Name, SP_ItemType Type, float Cost, SP_ItemCategory Category, SP_ItemOwner Owner, UTexture2D* Texture)
		:Name(Name), Type(Type), Cost(Cost), Category(Category), Owner(Owner)
	{
		bEmpty = false;
		ItemTexture = Texture;
	}

	FSP_Item(FString Name, SP_ItemType Type, float Cost, SP_ItemCategory Category, SP_ItemOwner Owner, bool Consumable, int NutritionalValue, UTexture2D* Texture)
		:Name(Name), Type(Type), Cost(Cost), Category(Category), Owner(Owner), Consumable(Consumable), NutritionalValue(NutritionalValue), bEmpty(false) 
	{
		ItemTexture = Texture;
	}

	bool operator==(const FSP_Item& OtherItem) const
	{
		if (Name == OtherItem.Name && Type == OtherItem.Type && Cost == OtherItem.Cost && Category == OtherItem.Category)
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
class STRATEGYPROTOTYPE_API USP_ItemFactory : public UObject
{
	GENERATED_BODY()

	UTexture2D* Texture;

public:
	static FSP_Item CreateItem(SP_ItemType Type, SP_ItemOwner Owner);
};
