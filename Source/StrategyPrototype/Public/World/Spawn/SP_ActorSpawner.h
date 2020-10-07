#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_ActorSpawner.generated.h"

class ASP_BaseCharacter;

UCLASS()
class STRATEGYPROTOTYPE_API USP_ActorSpawner : public UObject
{
	GENERATED_BODY()

	class ASP_GameMode* mGameMode;
	UWorld* mWorld;
	class USP_WorldState* mWorldState;

public:
	USP_ActorSpawner();

	void SpawnActor(TSubclassOf<AActor> ActorClass);

	void Init(UWorld* World);

	void SpawnCharacter(TSubclassOf<ASP_BaseCharacter> CharacterClass);
};
