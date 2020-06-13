// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYPROTOTYPE_API USP_InventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USP_InventoryWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextUnits;
	
};
