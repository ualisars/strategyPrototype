// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SP_BaseCharacter.h"
#include "SP_Town.h"
#include "Characters/SP_CharacterMode.h"
#include "SP_Player.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Player : public ASP_BaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASP_Player();

	SP_CharacterMode Mode;

	ASP_Town* TownToMove;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void InteractWithTown();
};
