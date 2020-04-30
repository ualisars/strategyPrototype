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
}

// Called when the game starts or when spawned
void ASP_Town::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASP_Town::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

