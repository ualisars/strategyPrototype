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

	FPlayerUnit Fermer = FPlayerUnit("Fermer", 10.0f, 2.0f);
	FPlayerUnit Villager = FPlayerUnit("Villager", 9.0f, 3.0f);
	FPlayerUnit Knight = FPlayerUnit("Knight", 50.0f, 12.0f);
	FPlayerUnit Mercernary = FPlayerUnit("Mercernary", 30.0f, 9.0f);
	AvailableUnits.Add(Fermer);
	AvailableUnits.Add(Villager);
	AvailableUnits.Add(Knight);
	AvailableUnits.Add(Mercernary);
}

