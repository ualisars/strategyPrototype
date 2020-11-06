#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_Town.h"
#include "SP_ActorSpawner.generated.h"

class ASP_BaseCharacter;

UCLASS()
class STRATEGYPROTOTYPE_API USP_ActorSpawner : public UObject
{
	GENERATED_BODY()

	UWorld* mWorld;
	class USP_WorldState* mWorldState;
	class ASP_WorldGenerator* mWorldGenerator;

	void SpawnCharacter(TSubclassOf<ASP_BaseCharacter> CharacterClass, const FVector& Location, const FRotator& Rotation);

public:
	USP_ActorSpawner();

	void Init(UWorld* World);

	void SpawnTown(
		TSubclassOf<ASP_Town> TownClass, 
		const FVector& Location, 
		const FRotator& Rotation, 
		FName Name,
		TArray<SP_BuildingType> Buildings,
		unsigned char Population
	);

	void SpawnNPC(TSubclassOf<ASP_BaseCharacter> NPCClass, const FVector& Location, const FRotator& Rotation);

	void SpawnPlayer(TSubclassOf<ASP_BaseCharacter> PlayerClass, TSubclassOf<class ASP_GameCamera> CameraClass, const FVector& Location, const FRotator& Rotation);
};
