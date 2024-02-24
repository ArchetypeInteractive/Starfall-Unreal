// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StarfallCharacter.h"
#include "StarfallVendorCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallVendorCharacter : public AStarfallCharacter
{
	GENERATED_BODY()
	
public:
	AStarfallVendorCharacter();

	virtual void BeginPlay() override;
};
