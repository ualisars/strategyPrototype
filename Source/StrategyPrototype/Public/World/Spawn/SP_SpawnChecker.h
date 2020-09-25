#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/EventSystem/SP_EventListener.h"
#include "SP_SpawnChecker.generated.h"


UCLASS()
class STRATEGYPROTOTYPE_API USP_SpawnChecker : public UObject, public SP_EventListener
{
	GENERATED_BODY()

	class ASP_GameMode* mGameMode;

public:
	USP_SpawnChecker();

	virtual void OnEvent(const SP_Event& Event) override;

	void CheckSpawn(const SP_Event& Event);
};
