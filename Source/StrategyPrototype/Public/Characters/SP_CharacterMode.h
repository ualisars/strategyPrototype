// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
enum class STRATEGYPROTOTYPE_API SP_CharacterMode: unsigned char
{
	Roaming, 
	Attacking, 
	Fighting,
	GoingToTown,
	InteractingWithTown,
};
