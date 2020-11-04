#include "World/Spawn/SP_ActorSpawner.h"
#include "Engine/World.h"
#include "SP_BaseCharacter.h"
#include "SP_NPC.h"
#include "SP_Player.h"
#include "World/WorldState/SP_WorldState.h"
#include "SP_GameCamera.h"
#include "World/Generation/SP_WorldGenerator.h"
#include "Kismet/GameplayStatics.h"
#include "SP_GameMode.h"
#include "GameFramework/Actor.h"

void USP_ActorSpawner::SpawnCharacter(TSubclassOf<ASP_BaseCharacter> CharacterClass, const FVector& Location, const FRotator& Rotation)
{
	FActorSpawnParameters SpawnParams;

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
		Character->AddListener(mWorldGenerator);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to add listener to character in ActorSpawner"));
	}
}

USP_ActorSpawner::USP_ActorSpawner()
{}

void USP_ActorSpawner::SpawnActor(TSubclassOf<AActor> ActorClass)
{}

void USP_ActorSpawner::Init(UWorld* World)
{
	mWorld = World;

	if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(World)))
	{
		mWorldState = GameMode->GetWorldState();

		if (mWorldState == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get World State in SpawnChecker"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get GameMode in ActorSpawner"));
	}

	if (ASP_WorldGenerator* WorldGenerator = Cast<ASP_WorldGenerator>(UGameplayStatics::GetActorOfClass(World, ASP_WorldGenerator::StaticClass())))
	{
		mWorldGenerator = WorldGenerator;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get WorldGenerator in ActorSpawner"));
	}
}

void USP_ActorSpawner::SpawnNPC(TSubclassOf<ASP_BaseCharacter> NPCClass, const FVector& Location, const FRotator& Rotation)
{
	SpawnCharacter(NPCClass, Location, Rotation);
}

void USP_ActorSpawner::SpawnPlayer(TSubclassOf<ASP_BaseCharacter> PlayerClass, TSubclassOf<class ASP_GameCamera> CameraClass, const FVector& PlayerLocation, const FRotator& PlayerRotation)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(PlayerLocation.X + 60.0f, PlayerLocation.Y, PlayerLocation.Z);
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	mWorld->SpawnActor<ASP_GameCamera>(CameraClass, Location, Rotation, SpawnParams);

	SpawnCharacter(PlayerClass, Location, Rotation);
}
