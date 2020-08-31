#include "World/Spawn/SP_NPCSpawner.h"
#include "Engine/World.h"

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
			NPC->SpawnDefaultController();
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

