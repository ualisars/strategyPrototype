#pragma once

#include "CoreMinimal.h"
#include "SP_BaseCharacter.h"
#include "SP_NPC.generated.h"

UENUM(BlueprintType)
enum class SP_NPCTask : uint8
{
	None,
	BuyProvision,
	HireUnits
};

UCLASS()
class STRATEGYPROTOTYPE_API ASP_NPC : public ASP_BaseCharacter
{
	GENERATED_BODY()

	class UAIPerceptionStimuliSourceComponent* Stimulus;

	void SetupStimulus();

protected:
	virtual void BeginPlay() override;

	SP_NPCTask Task;

	void BuyProvision();

	void HireUnits();

	bool HireUnit(FSP_Unit& Unit);

	void BuyFood(TArray<FSP_Item>& TownFood);

public:	
	ASP_NPC();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	int MinDailyFoodSupply = 2;

	int EssentialDailyFoodSupply = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RequiredUnits = 3;

	TArray<class ASP_Town*> VisitedTowns;

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	float GetDailyFoodConsumption() const;

	UFUNCTION(BlueprintCallable)
	int CountDailyFoodSupply();

	void MoveToTown(class ASP_Town* Town);

	void SetNPCTask(SP_NPCTask NewTask);

	SP_NPCTask GetNPCTask() const;

	UFUNCTION(BlueprintCallable)
	bool NeedFood();
};
