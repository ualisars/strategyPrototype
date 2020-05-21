// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class STRATEGYPROTOTYPE_API SP_Unit
{
public:
	FString Name;
	float Health;
	float Damage;

	SP_Unit();

	SP_Unit(const FString& Name, float Health, float Damage);
	~SP_Unit();
};
