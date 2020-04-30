// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SP_Town.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Town : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASP_Town();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
