#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SP_WorldGenerator.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_WorldGenerator : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_BaseCharacter> NPCClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_BaseCharacter> PlayerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_GameCamera> CameraClass;

	class USP_ActorSpawner* mActorSpawner;

	class USP_SpawnChecker* mSpawnChecker;

	void SetActorSpawner();

	void SetSpawnChecker();

	void InitWorld();
	
public:	
	ASP_WorldGenerator();

protected:
	virtual void BeginPlay() override;

public:
	USP_ActorSpawner* GetActorSpawner() const;

	class USP_SpawnChecker* GetSpawnChecker() const;
};
