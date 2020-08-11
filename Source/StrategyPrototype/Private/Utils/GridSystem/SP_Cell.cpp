#include "Utils/GridSystem/SP_Cell.h"

SP_Cell::SP_Cell()
{
}

SP_Cell::SP_Cell(float X, float Y, int Size): mX(X), mY(Y), mSize(Size)
{}

void SP_Cell::SetSafety(int Safety)
{
	if (Safety >= MinSafety && Safety <= MaxSafety)
	{
		mSafety = Safety;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to set safety, incorrect value passed"));
	}
}

void SP_Cell::AddSafety(int Value)
{
	if (Value >= MinSafety && Value <= MaxSafety)
	{
		mSafety += Value;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to set safety, incorrect value passed"));
	}
}

float SP_Cell::GetX()
{
	return mX;
}

float SP_Cell::GetY()
{
	return mY;
}

float SP_Cell::GetCenterX()
{
	return mX + mSize;
}

float SP_Cell::GetCenterY()
{
	return mY + mSize;
}

int SP_Cell::GetSafety()
{
	return mSafety;
}

SP_Cell::~SP_Cell()
{
}
