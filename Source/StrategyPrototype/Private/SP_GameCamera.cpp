#include "SP_GameCamera.h"

ASP_GameCamera::ASP_GameCamera()
{
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

void ASP_GameCamera::MouseWheelUp()
{
	if (SpringArmComp->TargetArmLength > CameraLowerHeightLimit)
	{
		SpringArmComp->TargetArmLength -= ScrollingSpeed;
	}
}

void ASP_GameCamera::MouseWheelDown()
{
	if (SpringArmComp->TargetArmLength < CameraUpperHeightLimit)
	{
		SpringArmComp->TargetArmLength += ScrollingSpeed;
	}
}

void ASP_GameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

void ASP_GameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &ASP_GameCamera::MoveXAxis);
	InputComponent->BindAxis("MoveY", this, &ASP_GameCamera::MoveYAxis);

	InputComponent->BindAction("MouseWheelUp", IE_Pressed, this, &ASP_GameCamera::MouseWheelUp);
	InputComponent->BindAction("MouseWheelDown", IE_Pressed, this, &ASP_GameCamera::MouseWheelDown);
}

