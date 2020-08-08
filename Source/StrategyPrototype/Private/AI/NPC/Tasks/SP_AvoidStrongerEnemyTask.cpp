#include "AI/NPC/Tasks/SP_AvoidStrongerEnemyTask.h"

USP_AvoidStrongerEnemyTask::USP_AvoidStrongerEnemyTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("AvoidStrongerEnemy");
}

EBTNodeResult::Type USP_AvoidStrongerEnemyTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Type();
}
