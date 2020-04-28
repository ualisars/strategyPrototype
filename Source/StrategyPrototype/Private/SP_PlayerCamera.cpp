// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_PlayerCamera.h"

// Sets default values
ASP_PlayerCamera::ASP_PlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
}

// Called when the game starts or when spawned
void ASP_PlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASP_PlayerCamera::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveForward"));
	AddMovementInput(GetActorForwardVector() * Value);
}

void ASP_PlayerCamera::MoveRight(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveRight"));
	AddMovementInput(GetActorRightVector() * Value);
}

// Called every frame
void ASP_PlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_PlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASP_PlayerCamera::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASP_PlayerCamera::MoveRight);
}

