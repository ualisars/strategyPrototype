#include "SP_GameStateBase.h"

void ASP_GameStateBase::SetClockwork(float DeltaTime)
{
	float ClockworkUnit = Clockwork + (DeltaTime / TimeUnit);
	int hours = 24;
	Clockwork = fmod(ClockworkUnit, hours);
	DayTick = ClockworkUnit / hours;
}

void ASP_GameStateBase::Clock()
{
	int SecondsInHour = 3600;
	int MinutesInHour = 60;
	float TimeUnit = (Clockwork * SecondsInHour) / MinutesInHour;
	Minutes = floor(fmod(TimeUnit, MinutesInHour));
	float HoursAndMinutes = TimeUnit / MinutesInHour;
	Hours = floor(fmod(HoursAndMinutes, MinutesInHour));

	GameTime[0] = Hours;
	GameTime[1] = Minutes;
}

void ASP_GameStateBase::Calendar()
{
	if (DayTick)
	{
		Day += DayTick;
		if (Day > 26)
		{
			Day = 1;
			Month += 1;
		}

		if (Month > 15)
		{
			Month = 1;
			Year += 1;
		}

		GameDate[0] = Day;
		GameDate[1] = Month;
		GameDate[2] = Year;
	}
}

TArray<AActor*> ASP_GameStateBase::GetCharacters()
{
	TSubclassOf<ASP_BaseCharacter> BaseCharacterClass = ASP_BaseCharacter::StaticClass();
	TArray<AActor*> BaseCharacterActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), BaseCharacterClass, BaseCharacterActors);
	return BaseCharacterActors;
}

void ASP_GameStateBase::ConsumeFood()
{
	TArray<AActor*> CharacterActors = GetCharacters();
	for (AActor* Actor : CharacterActors)
	{
		if (ASP_BaseCharacter* Character = Cast<ASP_BaseCharacter>(Actor))
		{
			Character->ConsumeFood();
		}
	}
}

void ASP_GameStateBase::CheckFoodConsumption(int CurrentHour)
{
	if (CurrentHour != LastEatHour && EatHours.Contains(CurrentHour))
	{
		ConsumeFood();
		LastEatHour = CurrentHour;
	}
}

void ASP_GameStateBase::MakeUnitPayment(int CurrentDay)
{
	if (Hours == PaymentHour && LastPaymentDay != CurrentDay)
	{
		TArray<AActor*> CharacterActors = GetCharacters();
		for (AActor* Actor : CharacterActors)
		{
			if (ASP_BaseCharacter* Character = Cast<ASP_BaseCharacter>(Actor))
			{
				Character->PayUnitsWage();
				LastPaymentDay = CurrentDay;
			}
		}
	}
}

ASP_GameStateBase::ASP_GameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GameTime.SetNum(2);
	GameDate = { 1, 1, 1 };
}

void ASP_GameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetClockwork(DeltaTime);

	Clock();

	Calendar();

	CheckFoodConsumption(Hours);

	MakeUnitPayment(Day);
}

void ASP_GameStateBase::BeginPlay()
{
	Super::BeginPlay();
}
