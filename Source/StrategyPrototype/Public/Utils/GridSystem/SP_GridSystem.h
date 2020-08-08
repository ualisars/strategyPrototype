#pragma once

#include "CoreMinimal.h"

class STRATEGYPROTOTYPE_API SP_GridSystem
{
	float mStartX, mStartY;
	int mGridWidth, mGridHeight, mGridSize;

	TArray<class SP_Cell> mGrid;
public:
	SP_GridSystem();

	void ConstructGrid(const class AActor* Actor);

	~SP_GridSystem();
};
