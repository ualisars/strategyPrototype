// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_PlayerCamera.h"

// Sets default values
ASP_PlayerCamera::ASP_PlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	UCameraComponent* PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	VisibleComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComp"));
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 200.0f));
	PlayerCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	VisibleComp->SetupAttachment(RootComponent);
	VisibleComp->SetCanEverAffectNavigation(false);
}

// Called when the game starts or when spawned
void ASP_PlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASP_PlayerCamera::Move_XAxis(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 600.0f; // 100.0f default
}

void ASP_PlayerCamera::Move_YAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 600.0f;
}

// Called every frame
void ASP_PlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ASP_PlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveX", this, &ASP_PlayerCamera::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &ASP_PlayerCamera::Move_YAxis);
}

