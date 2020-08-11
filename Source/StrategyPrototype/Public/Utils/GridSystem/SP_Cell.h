#pragma once

#include "CoreMinimal.h"

class STRATEGYPROTOTYPE_API SP_Cell
{
	float mX, mY;

	short mSafety = 0;

	short MinSafety = -5;
	short MaxSafety = 5;

	int mSize;
public:
	SP_Cell();

	SP_Cell(float X, float Y, int Size);

	void SetSafety(int Safety);

	void AddSafety(int Value);

	float GetX();

	float GetY();

	float GetCenterX();

	float GetCenterY();

	int GetSafety();

	~SP_Cell();
};
