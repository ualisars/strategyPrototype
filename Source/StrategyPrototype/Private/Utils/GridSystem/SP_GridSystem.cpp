#include "Utils/GridSystem/SP_GridSystem.h"
#include <math.h>

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

void SP_GridSystem::ConstructGrid(const AActor* Actor, const TArray<AActor*>& VisibleActors)
{
	for (float Y = mStartY; Y <= mGridHeight; Y += mCellSize)
	{
		for (float X = mStartX; X <= mGridWidth; X += mCellSize)
		{
			SP_Cell Cell = SP_Cell(X, Y, mCellSize);
			for (const AActor* Character : VisibleActors)
			{
				if(Cast<ASP_BaseCharacter>(Character))
					Cell.AssignSafety(Character);
			}
			mGrid.Add(Cell);
		}
	}
}

SP_GridSystem::~SP_GridSystem()
{
}
