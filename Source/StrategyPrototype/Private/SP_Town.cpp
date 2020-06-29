#include "SP_Town.h"

ASP_Town::ASP_Town()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	RootComponent = MeshComp;

	Tags.Add(FName("Town"));

	FSP_Unit Fermer = FSP_Unit("Fermer", 10.0f, 2.0f, 3.0f);
	FSP_Unit Villager = FSP_Unit("Villager", 9.0f, 3.0f, 3.0f);
	FSP_Unit Knight = FSP_Unit("Knight", 50.0f, 12.0f, 50.0f);
	FSP_Unit Mercernary = FSP_Unit("Mercernary", 30.0f, 9.0f, 30.0f);
	
	AvailableUnits.Add(Fermer);
	AvailableUnits.Add(Villager);
	AvailableUnits.Add(Knight);
	AvailableUnits.Add(Mercernary);

	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Sword, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Helmet, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Iron, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Copper, SP_ItemOwner::Town));
}

void ASP_Town::RemoveFromAvailableUnits(const FSP_Unit& Unit)
{
	AvailableUnits.Remove(Unit);
}

void ASP_Town::AddItem(FSP_Item& Item)
{
	Item.SetOwner(SP_ItemOwner::Town);
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
