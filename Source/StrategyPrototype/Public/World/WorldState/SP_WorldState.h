#pragma once

#include "CoreMinimal.h"

class STRATEGYPROTOTYPE_API SP_WorldState
{
	short mSafety = 0;
	short mStability = 0;
	short mStarvation = 0;
public:
	SP_WorldState();

	~SP_WorldState();

	short GetSafery();

	short GetStability();

	short GetStarvation();
};
