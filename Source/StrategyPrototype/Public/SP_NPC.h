// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SP_BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SP_NPC.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_NPC : public ASP_BaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASP_NPC();

	int CurrentTownIndex = 0;

	void UpdateCurrentTownIndex();

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

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
