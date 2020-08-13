#include "AI/NPC/Tasks/SP_AvoidStrongerEnemyTask.h"
#include "SP_AIController.h"
#include "SP_NPC.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Utils/GridSystem/SP_GridSystem.h"
#include "AI/SP_BlackboardKeys.h"

USP_AvoidStrongerEnemyTask::USP_AvoidStrongerEnemyTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("AvoidStrongerEnemy");
}

EBTNodeResult::Type USP_AvoidStrongerEnemyTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	SP_GridSystem GridSystem = SP_GridSystem(NPC, GridWidth, GridHeight, CellSize);
	GridSystem.ConstructGrid(NPC);

	SP_Cell SafestCell = GridSystem.GetSafestCell();

	const UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	FNavLocation Location;
	FVector Origin = FVector(SafestCell.GetCenterX(), SafestCell.GetCenterY(), 0.0f);

	if (NavSys->GetRandomPointInNavigableRadius(Origin, CellSize, Location, nullptr))
	{
		AIController->GetBlackboard()->SetValueAsVector(BBKeys::TargetLocation, Location.Location);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
