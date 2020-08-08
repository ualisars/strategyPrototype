#include "Utils/GridSystem/SP_GridSystem.h"
#include "Utils/GridSystem/SP_Cell.h"
#include "GameFramework/Actor.h"

SP_GridSystem::SP_GridSystem()
{
}

void SP_GridSystem::ConstructGrid(const AActor* Actor)
{
	for (float Y = mStartY; Y <= mGridHeight; Y += mGridSize)
	{
		for (float X = mStartX; X <= mGridWidth; X += mGridSize)
		{
			mGrid.Add(SP_Cell(X, Y));
		}
	}
}

SP_GridSystem::~SP_GridSystem()
{
}
