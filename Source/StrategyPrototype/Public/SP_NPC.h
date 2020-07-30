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
	ASP_NPC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void NPC_MoveToActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	float GetDailyFoodConsumption() const;
};
