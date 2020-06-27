#include "SP_Town.h"

ASP_Town::ASP_Town()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	RootComponent = MeshComp;

	FSP_Unit Fermer = FSP_Unit("Fermer", 10.0f, 2.0f, 3.0f);
	FSP_Unit Villager = FSP_Unit("Villager", 9.0f, 3.0f, 3.0f);
	FSP_Unit Knight = FSP_Unit("Knight", 50.0f, 12.0f, 50.0f);
	FSP_Unit Mercernary = FSP_Unit("Mercernary", 30.0f, 9.0f, 30.0f);
	
	AvailableUnits.Add(Fermer);
	AvailableUnits.Add(Villager);
	AvailableUnits.Add(Knight);
	AvailableUnits.Add(Mercernary);

	FSP_Item Bread1 = FSP_Item("Bread", 2.0f, SP_ItemType::Food, SP_ItemOwner::Town, true, 5);
	FSP_Item Bread2 = FSP_Item("Bread", 2.0f, SP_ItemType::Food, SP_ItemOwner::Town, true, 5);

	FSP_Item Sword = FSP_Item("Sword", 2.0f, SP_ItemType::Weapon, SP_ItemOwner::Town);
	FSP_Item Helmet = FSP_Item("Helmet", 2.0f, SP_ItemType::Armory, SP_ItemOwner::Town);
	FSP_Item Iron = FSP_Item("Iron", 2.0f, SP_ItemType::Resource, SP_ItemOwner::Town);
	FSP_Item Copper = FSP_Item("Copper", 2.0f, SP_ItemType::Resource, SP_ItemOwner::Town);

	Goods.Add(Bread1);
	Goods.Add(Bread2);
	Goods.Add(Sword);
	Goods.Add(Helmet);
	Goods.Add(Iron);
	Goods.Add(Copper);
}

void ASP_Town::RemoveFromAvailableUnits(const FSP_Unit& Unit)
{
	AvailableUnits.Remove(Unit);
}

void ASP_Town::AddItem(FSP_Item& Item)
{
	Goods.Add(Item);
}

FSP_Item ASP_Town::CreateDefaultItem()
{
	return FSP_Item();
}

void ASP_Town::RemoveItem(const FSP_Item& ItemToRemove)
{
	Goods.RemoveSingle(ItemToRemove);
}
