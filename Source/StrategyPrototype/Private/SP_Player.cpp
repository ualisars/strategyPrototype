// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Player.h"

// Sets default values
ASP_Player::ASP_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add(FName("Player"));

	Mode = SP_CharacterMode::Roaming;
}

// Called when the game starts or when spawned
void ASP_Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_Player::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag("Town"))
	{
		ASP_Town* Town = Cast<ASP_Town>(OtherActor);
		if (Town != nullptr && TownToMove != nullptr && TownToMove->Name == Town->Name)
		{
			InteractWithTown();
		}
		bOverlappingWithTown = true;
	}
}

void ASP_Player::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag("Town"))
	{
		bOverlappingWithTown = false;
	}
}

void ASP_Player::AddUnit(const FSP_Unit& PlayerUnit)
{
	FSP_Unit* Unit = new FSP_Unit(PlayerUnit.Name, PlayerUnit.Health, PlayerUnit.Damage);
	Units.Add(Unit);
}