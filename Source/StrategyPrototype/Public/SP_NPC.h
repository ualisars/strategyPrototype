// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h" 
#include "SP_NPC.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_NPC : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASP_NPC();

	void GetAllTowns();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UFloatingPawnMovement* FloatingPawnMovementComp;

	TArray<AActor*> Towns;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToActor(AActor* Actor);

};
