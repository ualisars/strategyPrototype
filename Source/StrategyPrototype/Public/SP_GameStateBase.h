#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include <math.h>
#include "SP_GameStateBase.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

	float TimeUnit = 2.5f;
	float Clockwork = 0.0f;
	int Hours = 0, Minutes = 0;
	int Day = 1, Month = 1, Year = 1;
	int DayTick;

	void SetClockwork(float DeltaTime);

	void Clock();

	void Calendar();

public:
	ASP_GameStateBase();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<int> GameTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<int> GameDate;

protected:
	void BeginPlay() override;
};
