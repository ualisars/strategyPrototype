#include "World/Spawn/SP_NPCSpawner.h"
#include "Engine/World.h"
#include "SP_GameMode.h"
#include "World/WorldState/SP_WorldState.h"
#include "Kismet/GameplayStatics.h"

void SP_NPCSpawner::SpawnNPC(UWorld* World, TSubclassOf<ASP_NPC> NPCClass)
{
	if (NPCClass)
	{
		if (!World)
		{
			UE_LOG(LogTemp, Warning, TEXT("World is nullptr in NPCSpawner"));
			return;
		}

		FActorSpawnParameters SpawnParams;
		FVector Location = FVector(0.0f, 0.0f, 0.0f);
		FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);
		SpawnParams.bAllowDuringConstructionScript = true;
		ASP_NPC* NPC = World->SpawnActor<ASP_NPC>(NPCClass, Location, Rotation, SpawnParams);

		if (NPC)
		{
			if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(World)))
			{
				NPC->SpawnDefaultController();
				
				if (USP_WorldState* WorldState = GameMode->GetWorldState())
				{
					NPC->AddListener(WorldState);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Failed to add observer in NPC"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to cast GameMode in NPC Spawner"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Error while spawning NPC"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NPC Class is not defined in NPCSpawner"));
	}
}

