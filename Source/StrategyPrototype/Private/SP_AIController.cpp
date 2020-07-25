#include "SP_AIController.h"

ASP_AIController::ASP_AIController(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> Obj(TEXT("BehaviorTree'/Game/AI/NPC/BT_Basic.BT_Basic'"));
	if (Obj.Succeeded())
	{
		BehaviorTree = Obj.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Behavior Tree not found at given path"));
	}

	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComp"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void ASP_AIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);
}

void ASP_AIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (Blackboard)
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

UBlackboardComponent * ASP_AIController::GetBlackboard() const
{
	return Blackboard;
}
