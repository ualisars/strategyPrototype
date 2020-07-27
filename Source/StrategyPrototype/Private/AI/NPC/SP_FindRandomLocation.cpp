#include "AI/NPC/SP_FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "SP_AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "SP_NPC.h"
#include "AI/SP_BlackboardKeys.h"

USP_FindRandomLocation::USP_FindRandomLocation(const FObjectInitializer & ObjectInitializer)
{
	NodeName = TEXT("FindRandomLocation");
}

EBTNodeResult::Type USP_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	const ASP_AIController* AIController = Cast<ASP_AIController>(OwnerComp.GetAIOwner());
	const ASP_NPC* NPC = Cast<ASP_NPC>(AIController->GetPawn());

	// obtain npc location
	const FVector Origin = NPC->GetActorLocation();
	FNavLocation Location;

	// get navigation system and generate a random location
	const UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location, nullptr))
	{
		AIController->GetBlackboard()->SetValueAsVector(BBKeys::TargetLocation, Location.Location);
	}
	
	// finish task with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}
