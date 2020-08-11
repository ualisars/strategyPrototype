#pragma once

#include "CoreMinimal.h"
#include "Utils/GridSystem/SP_Cell.h"

class STRATEGYPROTOTYPE_API SP_GridSystem
{
	float mStartX, mStartY;
	int mGridWidth, mGridHeight, mCellSize;

	TArray<SP_Cell> mGrid;

	int CalculateDistanceInCells(SP_Cell FromCell, SP_Cell ToCell);
public:
	SP_GridSystem();

	void ConstructGrid(const class AActor* Actor);

	~SP_GridSystem();
};
