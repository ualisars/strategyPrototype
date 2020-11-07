#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utils/SP_Random.h"
#include "Objects/SP_UnitFactory.h"
#include "Objects/SP_ItemFactory.h"
#include "Utils/EventSystem/SP_EventDispatcher.h"
#include "SP_BaseCharacter.generated.h"

class SP_Observer;

UENUM(BlueprintType)
enum class SP_CharacterMode : uint8
{
	Roaming,
	Attacking,
	Fighting,
	GoingToTown,
	InteractingWithTown,
	GoingToCharacter,
	InteractingWithCharacter
};

UCLASS()
class STRATEGYPROTOTYPE_API ASP_BaseCharacter : public ACharacter, public SP_EventDispatcher
{
	GENERATED_BODY()

	TArray<FSP_Item> Goods;

public:
	ASP_BaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MAX_INVENTORY_SLOTS = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Food = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Medicines;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float UnitPayment = 0.0f;

	ASP_BaseCharacter* OverlappingCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ASP_BaseCharacter* CharacterToMove;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FSP_Unit> Units;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float FoodConsumption = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class ASP_Town* TownToMove;

protected:
	virtual void BeginPlay() override;

	SP_CharacterMode Mode;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	FName CharacterName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Gold = 300.0f;

	float MAX_WALK_SPEED_DEFAULT = 300.0f;
	float MAX_WALK_SPEED_RODE = 400.0f;
	float MAX_WALK_SPEED_SWAMP = 100.0f;

	UCharacterMovementComponent* CharacterMovementComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* CharacterCollisionComp;

public:

	void Init(FName Name);

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void SetMode(SP_CharacterMode NewMode);

	UFUNCTION(BlueprintCallable)
	void AddUnit(const FSP_Unit& Unit);

	void AttackUnit(FSP_Unit* AttackUnit, FSP_Unit* DefendUnit);

	void StartBattle(ASP_BaseCharacter* OtherCharacter);

	void StopMovement();

	virtual void InteractWithCharacter();

	SP_CharacterMode GetMode();

	UFUNCTION(BlueprintCallable)
	void AddItem(FSP_Item& Item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FSP_Item& Item);

	UFUNCTION(BlueprintCallable)
	FName GetName() const;

	UFUNCTION(BlueprintCallable)
	void AddGold(float Value);

	float GetGold() const;

	UFUNCTION(BlueprintCallable)
	TArray<FSP_Item> GetGoods() const;

	void ConsumeFood();

	void PayUnitsWage();
};
