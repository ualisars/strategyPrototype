#include "World/Spawn/SP_ActorSpawner.h"
#include "Engine/World.h"
#include "SP_BaseCharacter.h"
#include "SP_NPC.h"
#include "SP_Player.h"
#include "World/WorldState/SP_WorldState.h"
#include "Kismet/GameplayStatics.h"
#include "SP_GameMode.h"
#include "GameFramework/Actor.h"

USP_ActorSpawner::USP_ActorSpawner()
{}

void USP_ActorSpawner::SpawnActor(TSubclassOf<AActor> ActorClass)
{}

void USP_ActorSpawner::Init(UWorld* World)
{
	mWorld = World;

	if (mWorld)
	{
		mGameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(mWorld));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get world reference in ActorSpawner"));
		return;
	}

	if (mGameMode)
	{
		mWorldState = mGameMode->GetWorldState();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get GameMode in ActorSpawner"));
		return;
	}
}

void USP_ActorSpawner::SpawnCharacter(TSubclassOf<ASP_BaseCharacter> CharacterClass)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(0.0f, 0.0f, 0.0f);
	FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);

	ASP_BaseCharacter* Character = mWorld->SpawnActor<ASP_BaseCharacter>(CharacterClass, Location, Rotation, SpawnParams);

	if (Character == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to spawn character"));
		return;
	}
	Character->SpawnDefaultController();

	if (mWorldState)
	{
		Character->AddListener(mWorldState);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to add listener to character in ActorSpawner"));
	}
}
