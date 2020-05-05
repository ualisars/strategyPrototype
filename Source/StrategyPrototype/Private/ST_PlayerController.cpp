// Fill out your copyright notice in the Description page of Project Settings.

#include "ST_PlayerController.h"

AST_PlayerController::AST_PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AST_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AST_PlayerController::LeftMousePressed()
{
	FHitResult LeftMouseHitResult;
	GetHitResultUnderCursorByChannel(TraceTypeQuery1, false, LeftMouseHitResult);

	float LocationX = LeftMouseHitResult.Location.X;
	UE_LOG(LogTemp, Warning, TEXT("LeftMousePressed"));
	UE_LOG(LogTemp, Warning, TEXT("X: %f, Y: %f, Z: %f"), LeftMouseHitResult.Location.X, LeftMouseHitResult.Location.Y, LeftMouseHitResult.Location.Z);
}

void AST_PlayerController::RightMousePressed()
{

}

void AST_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AST_PlayerController::LeftMousePressed);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &AST_PlayerController::RightMousePressed);
}
