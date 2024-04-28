// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "StarfallMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API UStarfallMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	



public:

	virtual void Crouch(bool bClientSimulation = false) override;
	virtual void UnCrouch(bool bClientSimulation = false) override;



	virtual void Sliding();


	virtual void Init();

};
