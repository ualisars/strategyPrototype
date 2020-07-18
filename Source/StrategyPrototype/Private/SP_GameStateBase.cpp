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
}

void ASP_GameStateBase::BeginPlay()
{
	Super::BeginPlay();
}
