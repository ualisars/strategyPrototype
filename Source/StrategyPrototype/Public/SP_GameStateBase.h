#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SP_GameStateBase.generated.h"


UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASP_GameStateBase();

	virtual void Tick(float DeltaTime) override;

protected:
	void BeginPlay() override;
};
