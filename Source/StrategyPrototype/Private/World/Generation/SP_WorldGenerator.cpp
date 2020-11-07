#include "World/Generation/SP_WorldGenerator.h"
#include "SP_GameMode.h"
#include "World/Spawn/SP_ActorSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"


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

void ASP_WorldGenerator::GetWorldState()
{
	if (ASP_GameMode* GameMode = Cast<ASP_GameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		mWorldState = GameMode->GetWorldState();

		if (mWorldState)
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to get World State in World Generator"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get Game Mode in World Generator"));
	}
}

void ASP_WorldGenerator::InitWorld()
{
	FVector Location = FVector(-520.0f, 130.0f, 58.0f);
	FRotator Rotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->SpawnPlayer(PlayerClass, CameraClass, Location, Rotation, "Lux");

	FVector NPCLocation = FVector(0.0f, 0.0f, 0.0f);
	FRotator NPCRotation = FRotator(0.0f, -90.0f, 0.0f);

	mActorSpawner->SpawnNPC(NPCClass, NPCLocation, NPCRotation, "Feol");

	FRotator TownRotation = FRotator(0.0f, 0.0f, 0.0f);

	FVector WenlisLocation = FVector(-780.0f, 750.0f, 0.0f);
	mActorSpawner->SpawnTown(TownClass, WenlisLocation, TownRotation, FName("Wenlis"), {SP_BuildingType::Pasture}, 200);
	
	FVector TerriumLocation = FVector(1330.0f, -600.0f, 0.0f);
	mActorSpawner->SpawnTown(TownClass, TerriumLocation, TownRotation, FName("Terrium"), {SP_BuildingType::WheatField }, 150);
}

ASP_WorldGenerator::ASP_WorldGenerator()
{
	// Hides visible components
	SetActorHiddenInGame(true);

	// Disables collision components
	SetActorEnableCollision(false);

	// Stops the Actor from ticking
	SetActorTickEnabled(false);

	// Event Subscription
	SubscribeForEvent(SP_EventType::FightOccured);
}

void ASP_WorldGenerator::BeginPlay()
{
	Super::BeginPlay();

	GetWorldState();

	SetActorSpawner();

	mActorSpawner->Init(GetWorld());
	
	InitWorld();
}

USP_ActorSpawner* ASP_WorldGenerator::GetActorSpawner() const
{
	return mActorSpawner;
}

void ASP_WorldGenerator::OnEvent(const SP_Event& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("On Event Check World Generator"));
	CheckSpawn(Event);
}

void ASP_WorldGenerator::CheckSpawn(const SP_Event& Event)
{
	if (mWorldState)
	{
		if (Event.GetType() == SP_EventType::FightOccured)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn NPC in World Generator"));

			// TODO: make random name generator
			FName NPCName = "NPC";
			mActorSpawner->SpawnNPC(NPCClass, FVector(FVector(0.0f, 0.0f, 0.0f)), FRotator(0.0f, -90.0f, 0.0f), NPCName);
		}
	}
}

