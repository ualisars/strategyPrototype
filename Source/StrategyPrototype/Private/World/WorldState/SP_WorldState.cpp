#include "World/WorldState/SP_WorldState.h"

uint8 USP_WorldState::mStability = 0;
uint8 USP_WorldState::mStarvation = 60;

USP_WorldState::USP_WorldState()
{
	SubscribeForEvent(SP_EventType::FightOccured);
}

uint8 USP_WorldState::GetStability()
{
	return mStability;
}

uint8 USP_WorldState::GetStarvation()
{
	return mStarvation;
}

void USP_WorldState::OnEvent(const SP_Event& Event)
{
	if (Event.GetType() == SP_EventType::FightOccured)
	{
		UE_LOG(LogTemp, Warning, TEXT("World State has been changed due to the fight"));
	}
}
