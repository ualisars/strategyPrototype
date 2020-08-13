#include "Utils/GridSystem/SP_GridSystem.h"
#include <math.h>

SP_GridSystem::SP_GridSystem()
{
}

SP_GridSystem::SP_GridSystem(const AActor* Actor, int GridWidth, int GridHeight, int CellSize)
{
	mGridWidth = GridWidth;
	mGridHeight = GridHeight;
	mCellSize = CellSize;
	FVector ActorLocation = Actor->GetActorLocation();
	mStartX = ActorLocation.X - (GridWidth / 2);
	mStartY = ActorLocation.Y - (GridHeight / 2);
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

SP_Cell SP_GridSystem::GetSafestCell()
{
	int SafestCellIndex = 0;
	for (int i = 1; i < mGrid.Num(); ++i)
	{
		if (mGrid[i].GetSafety() > mGrid[SafestCellIndex].GetSafety())
		{
			SafestCellIndex = i;
		}
	}

	return mGrid[SafestCellIndex];
}

SP_GridSystem::~SP_GridSystem()
{
}
