#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SP_MotivationSystem.generated.h"

UENUM(BlueprintType)
enum class SP_MotivationObjective : uint8
{
	Domination,
	Protection,
	Revenge,
	Wealth
};

USTRUCT(BlueprintType)
struct FSP_Motivation
{
	GENERATED_BODY()

	AActor* TargetActor = nullptr;

	SP_MotivationObjective Objective;

	unsigned char Aggression = 0;

	FSP_Motivation() {}

	FSP_Motivation(AActor* Actor, SP_MotivationObjective Objective, unsigned short Aggression)
		: TargetActor(Actor), Objective(Objective), Aggression(Aggression) {}
};

UCLASS()
class STRATEGYPROTOTYPE_API USP_MotivationSystem : public UObject
{
	GENERATED_BODY()

public:
	static FSP_Motivation DeriveMotivation();
};
