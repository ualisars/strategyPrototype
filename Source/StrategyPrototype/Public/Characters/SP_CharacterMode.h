#pragma once

#include "CoreMinimal.h"

enum class STRATEGYPROTOTYPE_API SP_CharacterMode: unsigned char
{
	Roaming, 
	Attacking, 
	Fighting,
	GoingToTown,
	InteractingWithTown,
	GoingToCharacter,
	InteractingWithCharacter
};
