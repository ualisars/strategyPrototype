#include "Objects/SP_UnitFactory.h"

FSP_Unit USP_UnitFactory::CreateUnit(SP_UnitType Type)
{
	switch (Type)
	{
		case SP_UnitType::Archer:
			return FSP_Unit("Archer", 40.0f, 16.0f, 15.0f);
		case SP_UnitType::Brigand:
			return FSP_Unit("Brigand", 120.0f, 20.0f, 30.0f);
		case SP_UnitType::Cavalry:
			return FSP_Unit("Cavalry", 130.0f, 30.0f, 40.0f);
		case SP_UnitType::Fermer:
			return FSP_Unit("Fermer", 40.0f, 8.0f, 8.0f);
		case SP_UnitType::Knight:
			return FSP_Unit("Knight", 150.0f, 40.0f, 50.0f);
		case SP_UnitType::Mercernary:
			return FSP_Unit("Mercernary", 140.0f, 25.0f, 40.0f);
		case SP_UnitType::Villager:
			return FSP_Unit("Villager", 30.0f, 8.0f, 5.0f);
		default:
			UE_LOG(LogTemp, Warning, TEXT("This type is not implemented in UnitFactory"));
			return FSP_Unit();
	}
}

