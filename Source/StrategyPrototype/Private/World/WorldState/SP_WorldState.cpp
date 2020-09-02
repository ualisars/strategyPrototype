#include "World/WorldState/SP_WorldState.h"

SP_WorldState::SP_WorldState()
{
}

SP_WorldState::~SP_WorldState()
{
}

short SP_WorldState::GetSafery()
{
	return mSafety;
}

short SP_WorldState::GetStability()
{
	return mStability;
}

short SP_WorldState::GetStarvation()
{
	return mStarvation;
}
