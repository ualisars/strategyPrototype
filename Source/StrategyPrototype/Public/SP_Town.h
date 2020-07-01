#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Objects/SP_Object.h"
#include "Objects/SP_ItemFactory.h"
#include "SP_Town.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Town : public AActor
{
	GENERATED_BODY()

public:	
	ASP_Town();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MAX_MARKET_SLOTS = 40;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	FName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> AvailableUnits;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
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
