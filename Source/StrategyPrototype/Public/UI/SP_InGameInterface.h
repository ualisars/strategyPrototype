// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_InGameInterface.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYPROTOTYPE_API USP_InGameInterface : public UUserWidget
{
	GENERATED_BODY()

public:
	USP_InGameInterface(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* MainText;
	
};
