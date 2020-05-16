// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_NPC.h"

// Sets default values
ASP_NPC::ASP_NPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
}

// Called when the game starts or when spawned
void ASP_NPC::BeginPlay()
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

void ASP_NPC::GetAllTowns()
{
	if (Towns.Num() == 0)
	{
		TArray<AActor*> FoundTowns;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Town", FoundTowns);
		UE_LOG(LogTemp, Warning, TEXT("Number of Found towns is %i"), FoundTowns.Num());
		FoundTowns.Sort([this](const AActor& Town1, const AActor& Town2) 
		{
			return GetDistanceTo(&Town1) < GetDistanceTo(&Town2);
		});
		Towns = FoundTowns;
	}
	UE_LOG(LogTemp, Warning, TEXT("Number of towns is %i"), Towns.Num());
}

// Called every frame
void ASP_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

