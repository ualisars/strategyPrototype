#include "AI/NPC/Tasks/SP_BuyProvisionTask.h"
#include "SP_AIController.h"
#include "SP_NPC.h"
#include "SP_Town.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/SP_BlackboardKeys.h"

AActor* USP_BuyProvisionTask::FindProvisionTown(ASP_NPC* NPC, TArray<AActor*> TownActors)
{
	AActor* Town = TownActors.Pop();
	if (NPC->NoProvisionTowns.Contains(Town))
	{
		if (TownActors.Num() > 0)
		{
			TownActors.Pop();
			return FindProvisionTown(NPC, TownActors);
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return Town;
	}
}

USP_BuyProvisionTask::USP_BuyProvisionTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("BuyProvision");
	bNotifyTaskFinished = true;
}

EBTNodeResult::Type USP_BuyProvisionTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8* NodeMemory)
{
	ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	TArray<AActor*> TownActors = AIController->GetTowns();
	TownActors.Sort([NPC, this](const AActor& Town1, const AActor& Town2)
	{
		return NPC->GetDistanceTo(&Town1) > NPC->GetDistanceTo(&Town2);
	});

	ASP_Town* Town = Cast<ASP_Town>(FindProvisionTown(NPC, TownActors));

	if (!Town)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}

	NPC->SetMode(SP_CharacterMode::GoingToTown);
	NPC->SetNPCTask(SP_NPCTask::BuyProvision);
	NPC->TownToMove = Town;
	
	AIController->GetBlackboard()->SetValueAsVector(BBKeys::TargetLocation, Town->GetActorLocation());
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
