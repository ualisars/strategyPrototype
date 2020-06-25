#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_Object.generated.h"

USTRUCT(BlueprintType)
struct FSP_Unit
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Cost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrCost;

	FSP_Unit() {}

	FSP_Unit(FString UnitName, float UnitHealth, float UnitDamage, float UnitCost)
		:Name(UnitName), Health(UnitHealth), Damage(UnitDamage), Cost(UnitCost)
	{
		StrHealth = FString::SanitizeFloat(UnitHealth);
		StrDamage = FString::SanitizeFloat(UnitDamage);
		StrCost = FString::SanitizeFloat(UnitCost);
	}

	FSP_Unit(FString UnitName, float UnitHealth, float UnitDamage)
		:Name(UnitName), Health(UnitHealth), Damage(UnitDamage)
	{
		StrHealth = FString::SanitizeFloat(UnitHealth);
		StrDamage = FString::SanitizeFloat(UnitDamage);
	}

	bool operator==(const FSP_Unit& OtherPlayerUnit) const
	{
		if (Name == OtherPlayerUnit.Name)
		{
			return true;
		}
		return false;
	}
};

UENUM(BlueprintType)
enum class SP_ItemType : uint8
{
	Armory,
	Food,
	Jewelry,
	Resource,
	Weapon
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
	bool Consumable = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int NutritionalValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bEmpty = true;

	FSP_Item() {}

	~FSP_Item() {}

	FSP_Item(FString Name, float Cost, SP_ItemType Type)
		:Name(Name), Cost(Cost), Type(Type) 
	{
		bEmpty = false;
	}

	FSP_Item(FString Name, float Cost, SP_ItemType Type, bool Consumable, int NutritionalValue)
		:Name(Name), Cost(Cost), Type(Type), Consumable(Consumable), NutritionalValue(NutritionalValue), bEmpty(false) {}

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
};

UCLASS()
class STRATEGYPROTOTYPE_API USP_Object : public UObject
{
	GENERATED_BODY()
	
};
