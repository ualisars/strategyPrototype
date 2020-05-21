// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SP_Brigand.h"

// Sets default values
ASP_Brigand::ASP_Brigand()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMode(SP_CharacterMode::Attacking);

	SP_Unit* Brigands = new SP_Unit("Brigand", 120, 5);
	Units.Add(Brigands);
}

// Called when the game starts or when spawned
void ASP_Brigand::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> FoundCharacters;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "NPC", FoundCharacters);
	if (FoundCharacters.Num() > 0)
	{
		Brigand_MoveToActor(FoundCharacters[0]);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No actors with NPC tag found"));
	}
}

// Called every frame
void ASP_Brigand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_Brigand::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

