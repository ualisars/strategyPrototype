#include "World/Spawn/SP_SpawnChecker.h"
#include "World/WorldState/SP_WorldState.h"
#include "SP_GameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SP_NPC.h"
#include "World/Spawn/SP_ActorSpawner.h"

USP_SpawnChecker::USP_SpawnChecker()
{
	SubscribeForEvent(SP_EventType::FightOccured);
}

void USP_SpawnChecker::OnEvent(const SP_Event& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("On Event Check Spawner"));
	CheckSpawn(Event);
}

void USP_SpawnChecker::CheckSpawn(const SP_Event& Event)
{
	if (mGameMode == nullptr)
		return;

	if (mWorldState)
	{
		if (Event.GetType() == SP_EventType::FightOccured && mWorldState->GetStarvation() > 50)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn NPC in Check Spawner"));
			mActorSpawner->SpawnNPC(ASP_NPC::StaticClass(), FVector(FVector(0.0f, 0.0f, 0.0f)), FRotator(0.0f, -90.0f, 0.0f));
		}
	}
}

void USP_SpawnChecker::Init(const UWorld* World)
{
	if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(World)))
	{
		mGameMode = GameMode;
		mWorldState = mGameMode->GetWorldState();
		mActorSpawner = mGameMode->GetActorSpawner();
		
		if (mWorldState == nullptr)
			UE_LOG(LogTemp, Warning, TEXT("Unable to get World State in SpawnChecker"));

		if (mActorSpawner == nullptr)
			UE_LOG(LogTemp, Warning, TEXT("Unable to get Actor Spawner in SpawnChecker"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get Game Mode in SpawnChecker"));
	}
}

