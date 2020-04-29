// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_GameCamera.h"

// Sets default values
ASP_GameCamera::ASP_GameCamera()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GameCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	GameCamera->SetupAttachment(RootComponent);
	GameCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 200.0f));
	GameCamera->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ASP_GameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASP_GameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASP_GameCamera::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void ASP_GameCamera::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// Called to bind functionality to input
void ASP_GameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASP_GameCamera::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASP_GameCamera::MoveRight);
}

