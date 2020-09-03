#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_SpawnChecker.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_SpawnChecker : public UObject
{
	GENERATED_BODY()

public:
	static void CheckSpawn();
};
