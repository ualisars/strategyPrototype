// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Obstacle.h"

// Sets default values
ASP_Obstacle::ASP_Obstacle()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &ASP_Obstacle::OnOverlapBegin);
	MeshComp->OnComponentEndOverlap.AddDynamic(this, &ASP_Obstacle::OnOverlapEnd);
	RootComponent = MeshComp;
}

void ASP_Obstacle::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
	}
}

void ASP_Obstacle::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
	}
}

// Called when the game starts or when spawned
void ASP_Obstacle::BeginPlay()
{
	Super::BeginPlay();
}

