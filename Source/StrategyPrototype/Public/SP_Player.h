#pragma once

#include "CoreMinimal.h"
#include "SP_BaseCharacter.h"
#include "SP_Town.h"
#include "SP_Player.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_Player : public ASP_BaseCharacter
{
	GENERATED_BODY()

public:
	ASP_Player();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ASP_Town* TownToMove;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> DisplayedUnits;

	ASP_Town* OverlappingTown;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToCharacter(ASP_BaseCharacter* OtherCharacter);

	UFUNCTION(BlueprintImplementableEvent)
	void InteractWithTown();

	UFUNCTION(BlueprintCallable)
	void AddUnit(const FSP_Unit& PlayerUnit);

	UFUNCTION(BlueprintImplementableEvent)
	void InteractWithCharacter() override;
};
