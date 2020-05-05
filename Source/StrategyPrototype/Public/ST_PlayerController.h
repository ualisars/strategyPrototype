// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ST_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYPROTOTYPE_API AST_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void LeftMousePressed();

	void RightMousePressed();

public:
	AST_PlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
};