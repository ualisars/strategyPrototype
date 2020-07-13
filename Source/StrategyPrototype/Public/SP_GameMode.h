#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SP_GameMode.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASP_GameMode();

protected:
	void BeginPlay() override;
};
