#include "World/WorldState/SP_WorldState.h"

uint8 USP_WorldState::mStability = 0;
uint8 USP_WorldState::mStarvation = 0;

USP_WorldState::USP_WorldState()
{
	UE_LOG(LogTemp, Warning, TEXT("World State constructor"));
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

void USP_WorldState::Update(const SP_Event& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("World State has been changed"));
}
