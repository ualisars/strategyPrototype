#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utils/SP_Random.h"
#include "Objects/SP_Object.h"
#include "Objects/SP_ItemFactory.h"
#include "Characters/SP_CharacterMode.h"
#include "SP_BaseCharacter.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASP_BaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MAX_INVENTORY_SLOTS = 15;

protected:
	virtual void BeginPlay() override;

	SP_CharacterMode Mode;

	float MAX_WALK_SPEED_DEFAULT = 300.0f;
	float MAX_WALK_SPEED_RODE = 400.0f;
	float MAX_WALK_SPEED_SWAMP = 100.0f;

	UCharacterMovementComponent* CharacterMovementComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* CharacterCollisionComp;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	TArray<FSP_Unit*> Units;

	void SetMode(SP_CharacterMode NewMode);

	void AttackUnit(FSP_Unit* AttackUnit, FSP_Unit* DefendUnit);

	void StartBattle(ASP_BaseCharacter* OtherCharacter);

	void StopMovement();

	virtual void InteractWithCharacter();

	SP_CharacterMode GetMode();
};
