#include "SP_GameMode.h"
#include "World/Spawn/SP_NPCSpawner.h"

ASP_GameMode::ASP_GameMode()
{}

void ASP_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASP_GameMode::BeginPlay()
{
	Super::BeginPlay();

	USP_NPCSpawner NPCSpawner;
	NPCSpawner.SpawnNPC(GetWorld(), NPCClass);
}
