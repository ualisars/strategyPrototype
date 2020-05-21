// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "random"
#include "CoreMinimal.h"

/**
 * 
 */
class STRATEGYPROTOTYPE_API SP_Random
{
public:
	SP_Random();
	~SP_Random();

	static int GenerateRandomNumber(int min, int max)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(min, max);
		return dis(gen);
	}
};
