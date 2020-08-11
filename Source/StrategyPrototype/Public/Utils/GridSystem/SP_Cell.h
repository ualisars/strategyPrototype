#pragma once

#include "CoreMinimal.h"

class STRATEGYPROTOTYPE_API SP_Cell
{
	float mX, mY;

	short mSafety = 0;

	short MinSafety = -5;
	short MaxSafety = 5;
public:
	SP_Cell();

	SP_Cell(float X, float Y);

	void SetSafety(int Safety);

	void AddSafety(int Value);

	int GetSafety();

	~SP_Cell();
};
