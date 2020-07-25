#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "SP_AIController.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;

	UBlackboardComponent* Blackboard;

public:
	ASP_AIController(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;

	void SetPawn(APawn* InPawn) override;

	UBlackboardComponent* GetBlackboard() const;
};
