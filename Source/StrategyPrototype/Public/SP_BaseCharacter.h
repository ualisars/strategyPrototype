// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Units/SP_Unit.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utils/SP_Random.h"
#include "Characters/SP_CharacterMode.h"
#include "SP_BaseCharacter.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASP_BaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	SP_CharacterMode Mode;

	float MAX_WALK_SPEED_DEFAULT = 300.0f;
	float MAX_WALK_SPEED_RODE = 400.0f;
	float MAX_WALK_SPEED_SWAMP = 100.0f;

	UCharacterMovementComponent* CharacterMovementComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	TArray<SP_Unit*> Units;

	void SetMode(SP_CharacterMode NewMode);

	void AttackUnit(SP_Unit* AttackUnit, SP_Unit* DefendUnit);

	void StartBattle(ASP_BaseCharacter* OtherCharacter);

	void StopMovement();

	SP_CharacterMode GetMode();
};
