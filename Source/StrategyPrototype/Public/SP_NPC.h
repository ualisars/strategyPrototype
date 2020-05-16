// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SP_NPC.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_NPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASP_NPC();

	void GetAllTowns();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
