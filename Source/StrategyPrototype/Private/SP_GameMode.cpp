#include "SP_GameMode.h"

void ASP_GameMode::SetWorldState()
{
	USP_WorldState* WorldState = NewObject<USP_WorldState>(USP_WorldState::StaticClass());

	if (WorldState)
	{
		mWorldState = WorldState;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create World State in Game Mode"));
	}
}

ASP_GameMode::ASP_GameMode()
{
	SetWorldState();
}

void ASP_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USP_WorldState* ASP_GameMode::GetWorldState() const
{
	return mWorldState;
}

void ASP_GameMode::BeginPlay()
{
	Super::BeginPlay();
}
