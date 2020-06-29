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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ASP_Town* TownToMove;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> DisplayedUnits;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Item> Goods;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Gold;

	bool bOverlappingWithTown = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void InteractWithTown();

	UFUNCTION(BlueprintCallable)
	void AddUnit(const FSP_Unit& PlayerUnit);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FSP_Item& Item);

	UFUNCTION(BlueprintCallable)
	FSP_Item CreateDefaultItem();

	UFUNCTION(BlueprintCallable)
	void AddItem(FSP_Item& Item);
};
