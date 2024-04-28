// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Starfall/Character/StarfallCharacter.h"
#include "GameplayTagContainer.h"
#include <Starfall/Character/Components/RadarComponent.h>
#include "StarfallEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallEnemyCharacter : public AStarfallCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;


public:
	AStarfallEnemyCharacter(const FObjectInitializer& ObjectInitializer);







	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Radar, meta = (AllowPrivateAccess = "true"))
	URadarComponent* Radar;
};
