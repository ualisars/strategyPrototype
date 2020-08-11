#include "Utils/GridSystem/SP_GridSystem.h"
#include "GameFramework/Actor.h"
#include <math.h>

int SP_GridSystem::CalculateDistanceInCells(SP_Cell FromCell, SP_Cell ToCell)
{
	float DX = std::abs(FromCell.GetCenterX() - ToCell.GetCenterX()) / mCellSize;
	float DY = std::abs(FromCell.GetCenterY() - ToCell.GetCenterY()) / mCellSize;
	return round(DX + DY);
}

SP_GridSystem::SP_GridSystem()
{
}

void SP_GridSystem::ConstructGrid(const AActor* Actor)
{
	for (float Y = mStartY; Y <= mGridHeight; Y += mCellSize)
	{
		for (float X = mStartX; X <= mGridWidth; X += mCellSize)
		{
			mGrid.Add(SP_Cell(X, Y, mCellSize));
		}
	}
}

SP_GridSystem::~SP_GridSystem()
{
}
