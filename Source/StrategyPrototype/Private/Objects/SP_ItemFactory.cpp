#include "Objects/SP_ItemFactory.h"

FSP_Item USP_ItemFactory::CreateItem(SP_ItemType Type, SP_ItemOwner Owner)
{
	switch (Type)
	{
		case SP_ItemType::Apple:
			return FSP_Item("Apple", 2.0f, SP_ItemCategory::Food, Owner, true, 5);
		case SP_ItemType::Axe:
			return FSP_Item("Axe", 5.0f, SP_ItemCategory::Weapon, Owner);
		case SP_ItemType::Bread:
			return FSP_Item("Bread", 2.0f, SP_ItemCategory::Food, Owner, true, 5);
		case SP_ItemType::Copper:
			return FSP_Item("Copper", 2.0f, SP_ItemCategory::Resource, Owner);
		case SP_ItemType::Helmet:
			return FSP_Item("Helmet", 2.0f, SP_ItemCategory::Armory, Owner);
		case SP_ItemType::Iron:
			return FSP_Item("Iron", 2.0f, SP_ItemCategory::Resource, Owner);
		case SP_ItemType::Sword:
			return FSP_Item("Sword", 2.0f, SP_ItemCategory::Weapon, Owner);
		case SP_ItemType::Wood:
			return FSP_Item("Wood", 1.0f, SP_ItemCategory::Resource, Owner);
		default:
			UE_LOG(LogTemp, Warning, TEXT("This type is not implemented in ItemFactory"));
			return FSP_Item();
	}
}

