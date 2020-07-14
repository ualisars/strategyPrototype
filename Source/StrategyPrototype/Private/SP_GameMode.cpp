#include "SP_GameMode.h"

void ASP_GameMode::SetClockwork(float DeltaTime)
{
	float ClockworkUnit = Clockwork + (DeltaTime / TimeUnit);
	int hours = 24;
	Clockwork = fmod(ClockworkUnit, hours);
	DayTick = ClockworkUnit / hours;
}

void ASP_GameMode::Clock()
{
	int SecondsInHour = 3600;
	int MinutesInHour = 60;
	float TimeUnit = (Clockwork * SecondsInHour) / MinutesInHour;
	Seconds = floor(fmod(TimeUnit, MinutesInHour));
	float HoursAndMinutes = TimeUnit / MinutesInHour;
	Minutes = floor(fmod(HoursAndMinutes, MinutesInHour));
	int HoursInDay = 24;
	float DaysAndHours = HoursAndMinutes / MinutesInHour;
	Hours = floor(fmod(DaysAndHours, HoursInDay));

	GameTime[0] = Hours;
	GameTime[1] = Minutes;
	GameTime[2] = Seconds;
}

void ASP_GameMode::Calendar()
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

ASP_GameMode::ASP_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	GameTime.SetNum(3);
	GameDate = { 1, 1, 1 };
}

void ASP_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetClockwork(DeltaTime);

	Clock();

	Calendar();
}

void ASP_GameMode::BeginPlay()
{
	Super::BeginPlay();
}
