#include "World/Spawn/SP_SpawnChecker.h"
#include "World/WorldState/SP_WorldState.h"
#include "SP_GameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "World/Generation/SP_WorldGenerator.h"
#include "SP_NPC.h"
#include "World/Spawn/SP_ActorSpawner.h"

USP_SpawnChecker::USP_SpawnChecker()
{
	SubscribeForEvent(SP_EventType::FightOccured);
}

void USP_SpawnChecker::OnEvent(const SP_Event& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("On Event Check World Generator"));
	CheckSpawn(Event);
}

void USP_SpawnChecker::CheckSpawn(const SP_Event& Event)
{
	if (mWorldState)
	{
		if (Event.GetType() == SP_EventType::FightOccured && mWorldState->GetStarvation() > 50)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn NPC in World Generator"));
			mActorSpawner->SpawnNPC(ASP_NPC::StaticClass(), FVector(FVector(0.0f, 0.0f, 0.0f)), FRotator(0.0f, -90.0f, 0.0f));
		}
	}
}

void USP_SpawnChecker::Init(UWorld* World, USP_ActorSpawner* ActorSpawner)
{
	mActorSpawner = ActorSpawner;

	/*
	if (mActorSpawner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get Actor Spawner in SpawnChecker"));
	}

	if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(World)))
	{
		mWorldState = GameMode->GetWorldState();
		
		if (mWorldState)
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get World State in SpawnChecker"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get Game Mode in SpawnChecker"));
	}
	*/
}

