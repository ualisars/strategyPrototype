#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/EventSystem/SP_Observer.h"
#include "SP_WorldState.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_WorldState : public UObject, public SP_Observer
{
	GENERATED_BODY()

	static uint8 mStability;
	static uint8 mStarvation;

public:
	UFUNCTION(BlueprintCallable)
	static uint8 GetStability();

	UFUNCTION(BlueprintCallable)
	static uint8 GetStarvation();

	virtual void Update() override;
};
