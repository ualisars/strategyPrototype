#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "SP_FindClosestTownTask.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_FindClosestTownTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	AActor* FindTown(class ASP_NPC* NPC, TArray<AActor*> TownActors);

public:
	USP_FindClosestTownTask(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
