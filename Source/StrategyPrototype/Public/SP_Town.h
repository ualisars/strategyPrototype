#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Objects/SP_UnitFactory.h"
#include "Objects/SP_ItemFactory.h"
#include "SP_Town.generated.h"

UENUM(BlueprintType)
enum class SP_BuildingType : uint8
{
	Pasture,
	WheatField
};

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Town : public AActor
{
	GENERATED_BODY()

	// town stats
	TArray<FSP_Item> mShortage;
	TArray<FSP_Item> mExcess;
	unsigned char mWealth = 0;
	unsigned char mFood = 0;
	unsigned char mPopulation = 0;

	TArray<SP_BuildingType> mBuildings;

public:	
	ASP_Town();

	void Init(FName TownName, TArray<SP_BuildingType> Buildings, unsigned char Population);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MAX_MARKET_SLOTS = 40;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	FName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> AvailableUnits;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	float MarketGold = 700.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	TArray<FSP_Item> Goods;

	UFUNCTION(BlueprintCallable)
	void RemoveFromAvailableUnits(const FSP_Unit& Unit);

	UFUNCTION(BlueprintCallable)
	void AddItem(FSP_Item& Item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FSP_Item& ItemToRemove);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;
};
