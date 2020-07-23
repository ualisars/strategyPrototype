#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_UnitFactory.generated.h"

UENUM(BlueprintType)
enum class SP_UnitType : uint8
{
	Archer,
	Brigand,
	Cavalry,
	Fermer,
	Knight,
	Mercernary,
	Villager
};

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
	float Payment;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Cost;

	float FoodConsumption = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StrCost;

	FSP_Unit() {}

	FSP_Unit(FString UnitName, float UnitHealth, float UnitDamage, float UnitPayment, float UnitCost)
		:Name(UnitName), Health(UnitHealth), Damage(UnitDamage), Payment(UnitPayment), Cost(UnitCost)
	{
		StrHealth = FString::SanitizeFloat(UnitHealth);
		StrDamage = FString::SanitizeFloat(UnitDamage);
		StrCost = FString::SanitizeFloat(UnitCost);
	}

	FSP_Unit(FString UnitName, float UnitHealth, float UnitDamage, float UnitPayment)
		:Name(UnitName), Health(UnitHealth), Damage(UnitDamage), Payment(Payment)
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

UCLASS()
class STRATEGYPROTOTYPE_API USP_UnitFactory : public UObject
{
	GENERATED_BODY()

public:
	static FSP_Unit CreateUnit(SP_UnitType);
};
