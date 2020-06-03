// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_Town.h"

// Sets default values
ASP_Town::ASP_Town()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	FSP_Item Bread1 = FSP_Item("Bread", 2.0f, SP_ItemType::Food, true, 5);
	FSP_Item Bread2 = FSP_Item("Bread", 2.0f, SP_ItemType::Food, true, 5);

	FSP_Item Sword = FSP_Item("Sword", 2.0f, SP_ItemType::Armory);
	FSP_Item Helmet = FSP_Item("Helmet", 2.0f, SP_ItemType::Jewelry);

	Goods.Add(Bread1);
	Goods.Add(Bread2);
	Goods.Add(Sword);
	Goods.Add(Helmet);
}

void ASP_Town::RemoveFromAvailableUnits(const FSP_Unit& Unit)
{
	AvailableUnits.Remove(Unit);
}
