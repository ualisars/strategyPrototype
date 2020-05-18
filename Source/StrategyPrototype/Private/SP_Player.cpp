// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Player.h"

// Sets default values
ASP_Player::ASP_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASP_Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

