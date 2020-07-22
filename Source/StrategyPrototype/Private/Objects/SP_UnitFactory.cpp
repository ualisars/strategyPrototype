#include "Objects/SP_UnitFactory.h"

FSP_Unit* USP_UnitFactory::CreateUnit(SP_UnitType Type)
{
	switch (Type)
	{
		case SP_UnitType::Archer:
			return new FSP_Unit("Archer", 40.0f, 16.0f, 15.0f);
		case SP_UnitType::Brigand:
			return new FSP_Unit("Brigand", 120.0f, 20.0f, 30.0f);
		case SP_UnitType::Cavalry:
			return new FSP_Unit("Cavalry", 130.0f, 30.0f, 40.0f);
		case SP_UnitType::Fermer:
			return new FSP_Unit("Fermer", 40.0f, 8.0f, 8.0f);
		case SP_UnitType::Knight:
			return new FSP_Unit("Knight", 150.0f, 40.0f, 50.0f);
		case SP_UnitType::Mercernary:
			return new FSP_Unit("Mercernary", 140.0f, 25.0f, 40.0f);
		case SP_UnitType::Villager:
			return new FSP_Unit("Villager", 30.0f, 8.0f, 5.0f);
		default:
			UE_LOG(LogTemp, Warning, TEXT("This type is not implemented in UnitFactory"));
			return new FSP_Unit();
	}
}

