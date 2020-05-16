// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Obstacle.h"

// Sets default values
ASP_Obstacle::ASP_Obstacle()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}


// Called when the game starts or when spawned
void ASP_Obstacle::BeginPlay()
{
	Super::BeginPlay();
}

