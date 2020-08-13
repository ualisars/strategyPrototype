#pragma once

#include "CoreMinimal.h"
#include "Utils/GridSystem/SP_Cell.h"
#include "SP_BaseCharacter.h"

class STRATEGYPROTOTYPE_API SP_GridSystem
{
	float mStartX, mStartY;
	int mGridWidth, mGridHeight, mCellSize;

	TArray<SP_Cell> mGrid;

public:
	SP_GridSystem();

	SP_GridSystem(const AActor* Actor, int GridWidth, int GridHeight, int CellSize);

	void ConstructGrid(const AActor* Actor);

	void ConstructGrid(const AActor* Actor, const TArray<AActor*>& VisibleActors);

	SP_Cell GetSafestCell();

	~SP_GridSystem();
};
