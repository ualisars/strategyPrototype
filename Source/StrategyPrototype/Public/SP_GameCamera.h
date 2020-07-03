#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "SP_GameCamera.generated.h"

UCLASS()
class STRATEGYPROTOTYPE_API ASP_GameCamera : public APawn
{
	GENERATED_BODY()

public:
	ASP_GameCamera();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	USceneComponent* RootScene;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly)
	float CameraSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly)
	float ScrollingSpeed = 50.0f;

	UPROPERTY(EditDefaultsOnly)
	float CameraUpperHeightLimit = 1500.0f;

	UPROPERTY(EditDefaultsOnly)
	float CameraLowerHeightLimit = 300.0f;

	UPROPERTY(EditDefaultsOnly)
	FVector CurrentVelocity;

	void MoveXAxis(float AxisValue);

	void MoveYAxis(float AxisValue);

	void MouseWheelUp();

	void MouseWheelDown();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
