#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "SP_BaseCharacter.h"
#include <math.h>
#include "SP_GameStateBase.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

	float TimeUnit = 2.5f;
	float Clockwork = 0.0f;
	int Hours = 6, Minutes = 0;
	int Day = 1, Month = 1, Year = 1;
	int DayTick;

	void SetClockwork(float DeltaTime);

	void Clock();

	void Calendar();

	TArray<AActor*> GetCharacters();

	// Food Consumption
	TArray<int> EatHours = { 9, 14, 20 };

	int LastEatHour = -1;

	void ConsumeFood();

	void CheckFoodConsumption(int Hour);

	// Unit Payment
	int PaymentHour = 12;

	int LastPaymentDay = 0;

	void MakeUnitPayment(int CurrentDay);

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
