// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StarfallCharacter.h"
#include "GameplayTagContainer.h"
#include "StarfallEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallEnemyCharacter : public AStarfallCharacter
{
	GENERATED_BODY()
	
public:
	AStarfallEnemyCharacter();






	virtual void BeginPlay() override;
};
