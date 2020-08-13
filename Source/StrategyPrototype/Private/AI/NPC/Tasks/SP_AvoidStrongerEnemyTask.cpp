#include "AI/NPC/Tasks/SP_AvoidStrongerEnemyTask.h"
#include "SP_AIController.h"
#include "SP_NPC.h"
#include "Utils/GridSystem/SP_GridSystem.h"

USP_AvoidStrongerEnemyTask::USP_AvoidStrongerEnemyTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("AvoidStrongerEnemy");
}

EBTNodeResult::Type USP_AvoidStrongerEnemyTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	return EBTNodeResult::Type();
}
