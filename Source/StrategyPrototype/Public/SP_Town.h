// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Units/SP_Unit.h"
#include "Components/StaticMeshComponent.h"
#include "Objects/SP_Object.h"
#include "SP_Town.generated.h"

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
	TArray<FSP_Unit> AvailableUnits;

	UFUNCTION(BlueprintCallable)
	void RemoveFromAvailableUnits(const FSP_Unit& Unit);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;
};
