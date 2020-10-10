#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "World/WorldState/SP_WorldState.h"
#include "World/Spawn/SP_ActorSpawner.h"
#include "SP_GameMode.generated.h"


UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_BaseCharacter> NPCClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_BaseCharacter> PlayerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_GameCamera> CameraClass;

	USP_WorldState* mWorldState;

	USP_ActorSpawner* mActorSpawner;

	class USP_SpawnChecker* mSpawnChecker;

	void SetWorldState();

	void SetActorSpawner();

	void SetSpawnChecker();

public:
	ASP_GameMode();

	virtual void Tick(float DeltaTime) override;

	USP_WorldState* GetWorldState() const;

	USP_ActorSpawner* GetActorSpawner() const;

	class USP_SpawnChecker* GetSpawnChecker() const;

protected:
	void BeginPlay() override;
};
