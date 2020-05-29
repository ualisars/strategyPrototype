// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Town.h"

// Sets default values
ASP_Town::ASP_Town()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	RootComponent = MeshComp;

	FPlayerUnit Fermer = FPlayerUnit("Fermer", "10.0", "2.0", "3.0");
	FPlayerUnit Villager = FPlayerUnit("Villager", "9.0", "3.0", "3.0");
	FPlayerUnit Knight = FPlayerUnit("Knight", "50.0", "12.0", "50.0");
	FPlayerUnit Mercernary = FPlayerUnit("Mercernary", "30.0", "9.0", "30.0");

	AvailableUnits.Add(Fermer);
	AvailableUnits.Add(Villager);
	AvailableUnits.Add(Knight);
	AvailableUnits.Add(Mercernary);
}

void ASP_Town::RemoveFromAvailableUnits(const FPlayerUnit& Unit)
{
	AvailableUnits.Remove(Unit);
}
