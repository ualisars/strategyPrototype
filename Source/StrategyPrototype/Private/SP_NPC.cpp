#include "SP_NPC.h"

ASP_NPC::ASP_NPC()
{
	FSP_Unit* Cavalry = new FSP_Unit("Cavalry", 70, 8);
	Units.Add(Cavalry);

	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::NPC));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Sword, SP_ItemOwner::NPC));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Necklace, SP_ItemOwner::NPC));

	CalculateFood();
}

void ASP_NPC::BeginPlay()
{
	Super::BeginPlay();
	
	GetAllTowns();
	if (Towns.Num() != 0)
	{
		FVector Location = Towns[0]->GetActorLocation();
		NPC_MoveToActor(Towns[CurrentTownIndex]);
	}
}

void ASP_NPC::UpdateCurrentTownIndex()
{
	if (CurrentTownIndex >= Towns.Num() - 1)
	{
		CurrentTownIndex = 0;
	}
	else
	{
		CurrentTownIndex += 1;
	}
}

void ASP_NPC::GetAllTowns()
{
	if (Towns.Num() == 0)
	{
		TArray<AActor*> FoundTowns;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Town", FoundTowns);
		FoundTowns.Sort([this](const AActor& Town1, const AActor& Town2) 
		{
			return GetDistanceTo(&Town1) < GetDistanceTo(&Town2);
		});
		Towns = FoundTowns;
	}
}

void ASP_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASP_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_NPC::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("Town"))
		{
			UpdateCurrentTownIndex();
			NPC_MoveToActor(Towns[CurrentTownIndex]);
		}
	}
}

