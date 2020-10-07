#include "SP_GameMode.h"
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

ASP_GameMode::ASP_GameMode()
{
	SetWorldState();
	SetActorSpawner();
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

void ASP_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = FVector(-520.0f, 130.0f, 58.0f);
	FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->Init(GetWorld());

	mActorSpawner->SpawnPlayer(PlayerClass, CameraClass, Location, Rotation);
}
