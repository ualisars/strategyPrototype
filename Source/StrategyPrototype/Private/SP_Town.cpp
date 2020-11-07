#include "SP_Town.h"

ASP_Town::ASP_Town()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	RootComponent = MeshComp;

	SetActorScale3D(FVector(1.75f, 1.75f, 1.0f));

	Tags.Add(FName("Town"));

	FSP_Unit Fermer = USP_UnitFactory::CreateUnit(SP_UnitType::Fermer);
	FSP_Unit Villager = USP_UnitFactory::CreateUnit(SP_UnitType::Villager);
	FSP_Unit Knight = USP_UnitFactory::CreateUnit(SP_UnitType::Knight);
	FSP_Unit Mercernary = USP_UnitFactory::CreateUnit(SP_UnitType::Mercernary);
	
	AvailableUnits.Add(Fermer);
	AvailableUnits.Add(Villager);
	AvailableUnits.Add(Knight);
	AvailableUnits.Add(Mercernary);

	//Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::Town));
	//Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Sword, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Helmet, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Iron, SP_ItemOwner::Town));
	Goods.Add(USP_ItemFactory::CreateItem(SP_ItemType::Copper, SP_ItemOwner::Town));
}

void ASP_Town::Init(FName TownName, TArray<SP_BuildingType> Buildings, unsigned char Population)
{
	Name = TownName;
	mBuildings = Buildings;
	mPopulation = Population;
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

void ASP_Town::RemoveItem(const FSP_Item& ItemToRemove)
{
	Goods.RemoveSingle(ItemToRemove);
}
