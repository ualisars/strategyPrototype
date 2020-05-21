// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_GameCamera.h"

// Sets default values
ASP_GameCamera::ASP_GameCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArmComp = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootScene);
	SpringArmComp->bDoCollisionTest = false;
	SpringArmComp->SetRelativeRotation(FRotator(-50.0f, 0.0f, 0.0f));

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ASP_GameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASP_GameCamera::MoveXAxis(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * CameraSpeed;
}

void ASP_GameCamera::MoveYAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * CameraSpeed;
}

// Called every frame
void ASP_GameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ASP_GameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &ASP_GameCamera::MoveXAxis);
	InputComponent->BindAxis("MoveY", this, &ASP_GameCamera::MoveYAxis);
}

