#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utils/EventSystem/SP_EventListener.h"
#include "SP_WorldGenerator.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_WorldGenerator : public AActor, public SP_EventListener
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

	class USP_WorldState* mWorldState;

	void SetActorSpawner();

	void GetWorldState();

	void InitWorld();
	
public:	
	ASP_WorldGenerator();

protected:
	virtual void BeginPlay() override;

public:
	class USP_ActorSpawner* GetActorSpawner() const;

	virtual void OnEvent(const SP_Event& Event) override;

	void CheckSpawn(const SP_Event& Event);
};
