#include "SP_Player.h"

ASP_Player::ASP_Player()
{
	Tags.Add(FName("Player"));

	FSP_Unit* Archer = new FSP_Unit("Archer", 10.0f, 6.0f);
	FSP_Unit DisplayedUnit = FSP_Unit(Archer->Name, Archer->Health, Archer->Damage);
	Units.Add(Archer);
	DisplayedUnits.Add(DisplayedUnit);

	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Apple, SP_ItemOwner::Player));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Axe, SP_ItemOwner::Player));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Wood, SP_ItemOwner::Player));
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

void ASP_Player::AddUnit(const FSP_Unit& PlayerUnit)
{
	FSP_Unit* Unit = new FSP_Unit(PlayerUnit.Name, PlayerUnit.Health, PlayerUnit.Damage);
	FSP_Unit DisplayedUnit = FSP_Unit(PlayerUnit.Name, PlayerUnit.Health, PlayerUnit.Damage);
	Units.Add(Unit);
	DisplayedUnits.Add(DisplayedUnit);
}

void ASP_Player::RemoveItem(const FSP_Item& Item)
{
	Goods.RemoveSingle(Item);
}

void ASP_Player::AddItem(FSP_Item& Item)
{
	Item.SetOwner(SP_ItemOwner::Player);
	Goods.Add(Item);
}
