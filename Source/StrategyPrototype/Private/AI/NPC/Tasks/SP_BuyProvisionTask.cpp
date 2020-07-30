#include "AI/NPC/Tasks/SP_BuyProvisionTask.h"
#include "SP_AIController.h"
#include "SP_NPC.h"
#include "SP_Town.h"

USP_BuyProvisionTask::USP_BuyProvisionTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("BuyProvision");
}

EBTNodeResult::Type USP_BuyProvisionTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	ASP_Town* Town = AIController->GetNearestTown();

	NPC->NPC_MoveToActor(Town);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}
