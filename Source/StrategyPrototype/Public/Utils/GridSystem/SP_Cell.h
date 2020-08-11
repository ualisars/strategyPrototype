#pragma once

#include "CoreMinimal.h"

class STRATEGYPROTOTYPE_API SP_Cell
{
	float mX, mY;

	short mSafety = 0;

	short MinSafety = -5;
	short MaxSafety = 5;

	int mSize;

	int CalculateDistanceBetweenCellAndActor(const class AActor* Actor);

	void SetSafety(int Safety);
public:
	SP_Cell();

	SP_Cell(float X, float Y, int Size);

	void AssignSafety(const class AActor* Actor);

	void AddSafety(int Value);

	float GetCenterX();

	float GetCenterY();

	int GetSafety();

	~SP_Cell();
};
