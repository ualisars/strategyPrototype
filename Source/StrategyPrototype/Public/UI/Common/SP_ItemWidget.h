// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SP_ItemWidget.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API USP_ItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USP_ItemWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* MainCanvasPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* ItemThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ItemName;
	
};
