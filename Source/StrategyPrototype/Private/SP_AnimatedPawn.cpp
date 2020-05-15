// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_AnimatedPawn.h"

// Sets default values
ASP_AnimatedPawn::ASP_AnimatedPawn()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASP_AnimatedPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASP_AnimatedPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_AnimatedPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

