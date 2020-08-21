#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "SP_AIController.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_AIController : public AAIController
{
	GENERATED_BODY()

	// Behavior Tree
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviorTree;

	class UBlackboardComponent* Blackboard;

	// Perception
	class UAISenseConfig_Sight* SightConfig;
	
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus);

	void SetupPerceptionSystem();

	TArray<AActor*> TownActors;

	void SetTowns();

public:
	ASP_AIController(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;

	void SetPawn(APawn* InPawn) override;

	class UBlackboardComponent* GetBlackboard() const;

	class ASP_Town* GetNearestTown();

	TArray<AActor*> GetTowns() const;

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetVisibleActors();
};
