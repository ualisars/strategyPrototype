#include "Utils/GridSystem/SP_Cell.h"
#include "GameFramework/Actor.h"

int SP_Cell::CalculateDistanceBetweenCellAndActor(const AActor* Actor)
{
	FVector ActorLocation = Actor->GetActorLocation();
	float DX = std::abs(GetCenterX() - ActorLocation.X) / mSize;
	float DY = std::abs(GetCenterY() - ActorLocation.Y) / mSize;
	return round(DX + DY);
}

void SP_Cell::SetSafety(int Safety)
{
	mSafety += Safety;
	if (mSafety < MinSafety)
	{
		mSafety = MinSafety;
	}
	else if (mSafety > MaxSafety)
	{
		mSafety = MaxSafety;
	}
}

SP_Cell::SP_Cell()
{
}

SP_Cell::SP_Cell(float X, float Y, int Size): mX(X), mY(Y), mSize(Size)
{}

void SP_Cell::AssignSafety(const AActor* Actor)
{
	int Distance = CalculateDistanceBetweenCellAndActor(Actor);
	int Safety = MaxSafety - Distance;
	if (Distance < MaxSafety)
		AddSafety(Safety);
}

void SP_Cell::AddSafety(int Value)
{
	if (Value >= MinSafety && Value <= MaxSafety)
	{
		int newSafety = mSafety += Value;
		SetSafety(newSafety);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to set safety, incorrect value passed"));
	}
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
