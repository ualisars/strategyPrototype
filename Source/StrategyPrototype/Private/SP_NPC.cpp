// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_NPC.h"

// Sets default values
ASP_NPC::ASP_NPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ASP_NPC::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ASP_NPC::OnOverlapEnd);
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
		NPC_MoveToActor(Towns[CurrentTownIndex]);
	}
}

void ASP_NPC::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
	}
}

void ASP_NPC::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
	}
}

void ASP_NPC::UpdateCurrentTownIndex()
{
	if (CurrentTownIndex >= Towns.Num())
		CurrentTownIndex = 0;
	CurrentTownIndex += 1;
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

	if (GetDistanceTo(Towns[CurrentTownIndex]) < 1.0f)
	{
		UpdateCurrentTownIndex();
		NPC_MoveToActor(Towns[CurrentTownIndex]);
	}

	
}

// Called to bind functionality to input
void ASP_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

