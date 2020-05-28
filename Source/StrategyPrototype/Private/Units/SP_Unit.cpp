// Fill out your copyright notice in the Description page of Project Settings.

#include "Units/SP_Unit.h"

SP_Unit::SP_Unit()
{
}

SP_Unit::SP_Unit(const FString & Name, float Health, float Damage) :
	Name(Name), Health(Health), Damage(Damage) {}

SP_Unit::~SP_Unit()
{
}