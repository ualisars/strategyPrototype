#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "SP_HireUnitsTask.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_HireUnitsTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	USP_HireUnitsTask(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
