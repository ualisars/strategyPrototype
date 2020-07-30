#include "SP_AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Town.h"

void ASP_AIController::GetTowns()
{
	TSubclassOf<ASP_Town> TownClass = ASP_Town::StaticClass();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), TownClass, TownActors);
}

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

	GetTowns();
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

ASP_Town* ASP_AIController::GetNearestTown()
{
	APawn* NPC = GetPawn();
	int NearestTownIndex = 0;
	for (int i = 1; i < TownActors.Num(); ++i)
	{
		if (NPC->GetDistanceTo(TownActors[i]) < NPC->GetDistanceTo(TownActors[NearestTownIndex]))
		{
			NearestTownIndex = i;
		}
	}
	
	return Cast<ASP_Town>(TownActors[NearestTownIndex]);
}
