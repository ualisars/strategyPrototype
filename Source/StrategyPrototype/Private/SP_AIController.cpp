#include "SP_AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Town.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "AI/SP_BlackboardKeys.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"

void ASP_AIController::OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor detected"));
}

void ASP_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
	SightConfig->SightRadius = 200.0f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
	SightConfig->PeripheralVisionAngleDegrees = 360.0f;
	SightConfig->SetMaxAge(10.0f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 900.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	// add sight configuration component to perception component
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ASP_AIController::OnTargetDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void ASP_AIController::SetTowns()
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

	SetupPerceptionSystem();
}

void ASP_AIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);

	SetTowns();
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

TArray<AActor*> ASP_AIController::GetTowns() const
{
	return TownActors;
}

TArray<AActor*> ASP_AIController::GetVisibleActors()
{
	TArray<AActor*> VisibleActors;
	GetPerceptionComponent()->GetCurrentlyPerceivedActors(*SightConfig->GetSenseImplementation(), VisibleActors);
	return VisibleActors;
}
