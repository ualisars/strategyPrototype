#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <math.h>
#include "SP_GameMode.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	float TimeUnit = 1.0f;
	float Clockwork = 0.0f;
	int Seconds = 0, Minutes = 0, Hours = 0;
	TArray<int> GameTime;
	int Day = 1, Month = 1, Year = 1;
	TArray<int> GameDate;
	int DayTick;

	void SetClockwork(float DeltaTime);

	void Clock();

	void Calendar();

public:
	ASP_GameMode();

	virtual void Tick(float DeltaTime) override;

protected:
	void BeginPlay() override;
};
