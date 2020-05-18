// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_BaseCharacter.h"

// Sets default values
ASP_BaseCharacter::ASP_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;
}

// Called when the game starts or when spawned
void ASP_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASP_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_BaseCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("BaseChar start overlap"));
	if (OtherActor && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("Road"))
		{
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_RODE;
		}
		else if (OtherActor->ActorHasTag("Swamp"))
		{
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_SWAMP;
		}
	}
}

void ASP_BaseCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("BaseChar end overlap"));
	if (OtherActor && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("NavigationArea"))
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;
	}
}

