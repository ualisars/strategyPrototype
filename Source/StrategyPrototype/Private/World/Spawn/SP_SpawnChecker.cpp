#include "World/Spawn/SP_SpawnChecker.h"
#include "World/WorldState/SP_WorldState.h"
#include "SP_GameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SP_NPC.h"
#include "World/Spawn/SP_ActorSpawner.h"

USP_SpawnChecker::USP_SpawnChecker()
{}

void USP_SpawnChecker::OnEvent(const SP_Event& Event)
{
	CheckSpawn(Event);
}

void USP_SpawnChecker::CheckSpawn(const SP_Event& Event)
{
	if (mGameMode == nullptr)
		return;

	if (USP_WorldState* WorldState = mGameMode->GetWorldState())
	{
		if (Event.GetType() == SP_EventType::FightOccured && WorldState->GetStarvation() > 50)
		{
			USP_ActorSpawner* ActorSpawner = mGameMode->GetActorSpawner();
			ActorSpawner->SpawnNPC(ASP_NPC::StaticClass(), FVector(FVector(-420.0f, 120.0f, 0.0f)), FRotator(0.0f, -90.0f, 0.0f));
		}
	}
}

void USP_SpawnChecker::Init(const UWorld* World)
{
	if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(World)))
	{
		mGameMode = GameMode;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get Game Mode in SpawnChecker"));
	}
}

