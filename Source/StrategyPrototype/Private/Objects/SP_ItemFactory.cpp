#include "Objects/SP_ItemFactory.h"

FSP_Item USP_ItemFactory::CreateItem(SP_ItemType Type, SP_ItemOwner Owner)
{
	ConstructorHelpers::FObjectFinder<UTexture2D> AppleTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/apple.apple'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> AxeTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/battle-axe.battle-axe'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> BreadTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/bread.bread'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> CopperTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/copper.copper'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> HelmetTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/helmet.helmet'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> IronTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/iron.iron'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SwordTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/sword.sword'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> WoodTextureTextObj(TEXT("TEXTURE2D'/Game/Textures/wood.wood'"));
	
	switch (Type)
	{
		case SP_ItemType::Apple:
			return FSP_Item("Apple", Type, 2.0f, SP_ItemCategory::Food, Owner, true, 5, AppleTextureTextObj.Object);
		case SP_ItemType::Axe:
			return FSP_Item("Axe", Type, 5.0f, SP_ItemCategory::Weapon, Owner, AxeTextureTextObj.Object);
		case SP_ItemType::Bread:
			return FSP_Item("Bread", Type, 2.0f, SP_ItemCategory::Food, Owner, true, 5, BreadTextureTextObj.Object);
		case SP_ItemType::Copper:
			return FSP_Item("Copper", Type, 2.0f, SP_ItemCategory::Resource, Owner, CopperTextureTextObj.Object);
		case SP_ItemType::Helmet:
			return FSP_Item("Helmet", Type, 2.0f, SP_ItemCategory::Armory, Owner, HelmetTextureTextObj.Object);
		case SP_ItemType::Iron:
			return FSP_Item("Iron", Type, 2.0f, SP_ItemCategory::Resource, Owner, IronTextureTextObj.Object);
		case SP_ItemType::Sword:
			return FSP_Item("Sword", Type, 2.0f, SP_ItemCategory::Weapon, Owner, SwordTextureTextObj.Object);
		case SP_ItemType::Wood:
			return FSP_Item("Wood", Type, 1.0f, SP_ItemCategory::Resource, Owner, WoodTextureTextObj.Object);
		default:
			UE_LOG(LogTemp, Warning, TEXT("This type is not implemented in ItemFactory"));
			return FSP_Item();
	}
}

