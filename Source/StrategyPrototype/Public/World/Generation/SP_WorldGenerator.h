#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SP_WorldGenerator.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_WorldGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	ASP_WorldGenerator();

protected:
	virtual void BeginPlay() override;
};
