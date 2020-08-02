#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "SP_BuyProvisionTask.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_BuyProvisionTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	AActor* FindProvisionTown(class ASP_NPC* NPC, TArray<AActor*> TownActors);

public:
	USP_BuyProvisionTask(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
