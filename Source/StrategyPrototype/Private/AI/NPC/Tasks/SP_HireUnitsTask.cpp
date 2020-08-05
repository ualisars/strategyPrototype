#include "AI/NPC/Tasks/SP_HireUnitsTask.h"
#include "SP_AIController.h"
#include "SP_NPC.h"

USP_HireUnitsTask::USP_HireUnitsTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("HireUnits");
}

EBTNodeResult::Type USP_HireUnitsTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	NPC->SetNPCTask(SP_NPCTask::HireUnits);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
