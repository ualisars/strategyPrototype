#include "SP_GameMode.h"
#include "World/Spawn/SP_SpawnChecker.h"
#include "Kismet/GameplayStatics.h"

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

void ASP_GameMode::SetActorSpawner()
{
	USP_ActorSpawner* ActorSpawner = NewObject<USP_ActorSpawner>(USP_ActorSpawner::StaticClass());

	if (ActorSpawner)
	{
		mActorSpawner = ActorSpawner;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create Actor Spawner in Game Mode"));
	}
}

void ASP_GameMode::SetSpawnChecker()
{
	USP_SpawnChecker* SpawnChecker = NewObject<USP_SpawnChecker>(USP_SpawnChecker::StaticClass());

	if (SpawnChecker)
	{
		mSpawnChecker = SpawnChecker;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create Spawn Checker in Game Mode"));
	}
}

ASP_GameMode::ASP_GameMode()
{
	SetWorldState();
	SetActorSpawner();
	SetSpawnChecker();
}

void ASP_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USP_WorldState* ASP_GameMode::GetWorldState() const
{
	return mWorldState;
}

USP_ActorSpawner* ASP_GameMode::GetActorSpawner() const
{
	return mActorSpawner;
}

USP_SpawnChecker * ASP_GameMode::GetSpawnChecker() const
{
	return mSpawnChecker;
}

void ASP_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = FVector(-520.0f, 130.0f, 58.0f);
	FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->Init(GetWorld());
	mSpawnChecker->Init(GetWorld());

	mActorSpawner->SpawnPlayer(PlayerClass, CameraClass, Location, Rotation);

	FVector NPCLocation = FVector(0.0f, 0.0f, 0.0f);
	FRotator NPCRotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->SpawnNPC(NPCClass, NPCLocation, NPCRotation);
}
