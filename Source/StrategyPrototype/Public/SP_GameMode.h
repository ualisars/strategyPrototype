#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "World/WorldState/SP_WorldState.h"
#include "SP_GameMode.generated.h"


UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASP_NPC> NPCClass;

	USP_WorldState* mWorldState;

	void SetWorldState();

public:
	ASP_GameMode();

	virtual void Tick(float DeltaTime) override;

	USP_WorldState* GetWorldState() const;

protected:
	void BeginPlay() override;
};
