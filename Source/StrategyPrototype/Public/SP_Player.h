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
	ASP_Player();

	SP_CharacterMode Mode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ASP_Town* TownToMove;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> DisplayedUnits;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Item> Goods;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Gold;

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

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FSP_Item& Item);

	UFUNCTION(BlueprintCallable)
	void AddItem(FSP_Item& Item);

	UFUNCTION(BlueprintImplementableEvent)
	void InteractWithCharacter() override;
};
