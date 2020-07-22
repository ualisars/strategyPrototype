#include "SP_Player.h"

ASP_Player::ASP_Player()
{
	Tags.Add(FName("Player"));

	FSP_Unit Archer = USP_UnitFactory::CreateUnit(SP_UnitType::Archer);

	Units.Add(Archer);

	FSP_Item Item1 = USP_ItemFactory::CreateItem(SP_ItemType::Apple, SP_ItemOwner::Player);
	FSP_Item Item2 = USP_ItemFactory::CreateItem(SP_ItemType::Axe, SP_ItemOwner::Player);
	FSP_Item Item3 = USP_ItemFactory::CreateItem(SP_ItemType::Wood, SP_ItemOwner::Player);

	AddItem(Item1);
	AddItem(Item2);
	AddItem(Item3);
}

void ASP_Player::BeginPlay()
{
	Super::BeginPlay();
}

void ASP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_Player::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag("Town"))
	{
		if (ASP_Town* Town = Cast<ASP_Town>(OtherActor))
		{
			if (TownToMove != nullptr && TownToMove->Name == Town->Name)
			{
				InteractWithTown();
			}
			OverlappingTown = Town;
		}
	}
}

void ASP_Player::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag("Town"))
	{
		OverlappingTown = nullptr;
	}
}
