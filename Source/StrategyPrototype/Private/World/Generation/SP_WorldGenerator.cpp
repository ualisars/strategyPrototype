#include "World/Generation/SP_WorldGenerator.h"
#include "World/Spawn/SP_ActorSpawner.h"
#include "World/Spawn/SP_SpawnChecker.h"


void ASP_WorldGenerator::SetActorSpawner()
{
	USP_ActorSpawner* ActorSpawner = NewObject<USP_ActorSpawner>(USP_ActorSpawner::StaticClass());

	if (ActorSpawner)
	{
		mActorSpawner = ActorSpawner;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create Actor Spawner in World Generator"));
	}
}

void ASP_WorldGenerator::SetSpawnChecker()
{
	USP_SpawnChecker* SpawnChecker = NewObject<USP_SpawnChecker>(USP_SpawnChecker::StaticClass());

	if (SpawnChecker)
	{
		mSpawnChecker = SpawnChecker;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create Spawn Checker in World Generator"));
	}
}

void ASP_WorldGenerator::InitWorld()
{
	FVector Location = FVector(-520.0f, 130.0f, 58.0f);
	FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->SpawnPlayer(PlayerClass, CameraClass, Location, Rotation);

	FVector NPCLocation = FVector(0.0f, 0.0f, 0.0f);
	FRotator NPCRotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->SpawnNPC(NPCClass, NPCLocation, NPCRotation);
}

ASP_WorldGenerator::ASP_WorldGenerator()
{
	// Hides visible components
	SetActorHiddenInGame(true);

	// Disables collision components
	SetActorEnableCollision(false);

	// Stops the Actor from ticking
	SetActorTickEnabled(false);

	SetActorSpawner();
	SetSpawnChecker();
}

void ASP_WorldGenerator::BeginPlay()
{
	Super::BeginPlay();

	mActorSpawner->Init(GetWorld());
	//mSpawnChecker->Init(GetWorld(), mActorSpawner);

	InitWorld();
}

USP_ActorSpawner* ASP_WorldGenerator::GetActorSpawner() const
{
	return mActorSpawner;
}

USP_SpawnChecker* ASP_WorldGenerator::GetSpawnChecker() const
{
	return mSpawnChecker;
}

