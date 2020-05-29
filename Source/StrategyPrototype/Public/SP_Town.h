// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Units/SP_Unit.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DataTable.h"
#include "SP_Town.generated.h"

USTRUCT(BlueprintType)
struct FPlayerUnit
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Health;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Damage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Cost;

	FPlayerUnit() {}

	FPlayerUnit(FString Name, FString Health, FString Damage, FString Cost)
		:Name(Name), Health(Health), Damage(Damage), Cost(Cost) {}

	bool operator==(const FPlayerUnit& OtherPlayerUnit)
	{
		if (Name == OtherPlayerUnit.Name)
		{
			return true;
		}
		return false;
	}
};

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Town : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASP_Town();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FPlayerUnit> AvailableUnits;

	UFUNCTION(BlueprintCallable)
	void RemoveFromAvailableUnits(const FPlayerUnit& Unit);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;
};
