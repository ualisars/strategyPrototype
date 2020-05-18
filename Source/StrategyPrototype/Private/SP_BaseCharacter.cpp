// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_BaseCharacter.h"

// Sets default values
ASP_BaseCharacter::ASP_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ASP_BaseCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ASP_BaseCharacter::OnOverlapEnd);

	CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;
}

// Called when the game starts or when spawned
void ASP_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASP_BaseCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
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

void ASP_BaseCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));

		if (OtherActor->ActorHasTag("NavigationArea"))
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;
	}
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

