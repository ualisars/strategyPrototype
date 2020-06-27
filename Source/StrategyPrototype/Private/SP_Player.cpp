#include "SP_Player.h"

ASP_Player::ASP_Player()
{
	Tags.Add(FName("Player"));

	Mode = SP_CharacterMode::Roaming;

	FSP_Unit* Archer = new FSP_Unit("Archer", 10.0f, 6.0f);
	FSP_Unit DisplayedUnit = FSP_Unit(Archer->Name, Archer->Health, Archer->Damage);
	Units.Add(Archer);
	DisplayedUnits.Add(DisplayedUnit);

	FSP_Item Apple = FSP_Item("Apple", 2.0f, SP_ItemType::Food, SP_ItemOwner::Player, true, 5);
	FSP_Item Axe = FSP_Item("Axe", 5.0f, SP_ItemType::Weapon, SP_ItemOwner::Player);
	FSP_Item Wood = FSP_Item("Wood", 1.0f, SP_ItemType::Resource, SP_ItemOwner::Player);

	Goods.Add(Apple);
	Goods.Add(Axe);
	Goods.Add(Wood);
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
	FSP_Unit DisplayedUnit = FSP_Unit(PlayerUnit.Name, PlayerUnit.Health, PlayerUnit.Damage);
	Units.Add(Unit);
	DisplayedUnits.Add(DisplayedUnit);
}

void ASP_Player::RemoveItem(const FSP_Item& Item)
{
	Goods.RemoveSingle(Item);
}

FSP_Item ASP_Player::CreateDefaultItem()
{
	return FSP_Item();
}

void ASP_Player::AddItem(FSP_Item& Item)
{
	Item.SetOwner(SP_ItemOwner::Player);
	Goods.Add(Item);
}
