// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Enemy.h"

// Sets default values
ASP_Enemy::ASP_Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ASP_Enemy::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

// Called every frame
void ASP_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASP_Enemy::Move()
{
	AController* PawnController = GetController();
	FVector GoalVector = FVector(0.0f, 0.0f, 0.0f);
	UNavigationSystem::SimpleMoveToLocation(PawnController, GoalVector);
}

// Called to bind functionality to input
void ASP_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

