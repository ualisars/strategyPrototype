#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SP_AIController.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviorTree;

	class UBlackboardComponent* Blackboard;

	TArray<AActor*> TownActors;

	void GetTowns();

public:
	ASP_AIController(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;

	void SetPawn(APawn* InPawn) override;

	class UBlackboardComponent* GetBlackboard() const;

	class ASP_Town* GetNearestTown();
};
