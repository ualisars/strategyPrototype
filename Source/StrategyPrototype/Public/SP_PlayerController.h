// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Player.h"
#include "SP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYPROTOTYPE_API ASP_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void LeftMousePressed();

	void RightMousePressed();

public:
	ASP_PlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
};
