// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_AnimatedPawn.h"

// Sets default values
ASP_AnimatedPawn::ASP_AnimatedPawn()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASP_AnimatedPawn::BeginPlay()
{
	Super::BeginPlay();
	
	GetAllTowns();
	if (Towns.Num() != 0)
	{
		FVector Location = Towns[0]->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("NPC is moving to x:%f, y:%f, z:%f"), Location.X, Location.Y, Location.Z);
		NPC_MoveToActor(Towns[0]);
	}
}

void ASP_AnimatedPawn::GetAllTowns()
{
	if (Towns.Num() == 0)
	{
		TArray<AActor*> FoundTowns;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Town", FoundTowns);
		UE_LOG(LogTemp, Warning, TEXT("Number of Found towns is %i"), FoundTowns.Num());
		Towns = FoundTowns;
	}
	UE_LOG(LogTemp, Warning, TEXT("Number of towns is %i"), Towns.Num());
}

// Called every frame
void ASP_AnimatedPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_AnimatedPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

