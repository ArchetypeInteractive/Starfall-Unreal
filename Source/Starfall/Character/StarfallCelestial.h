// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StarfallCharacter.h"
#include "AbilitySystemComponent.h"
#include "StarfallCelestial.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallCelestial : public AStarfallCharacter
{
	GENERATED_BODY()
	
protected:

public:
	AStarfallCelestial(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystem;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystem; };


	void SetupAbilitySystem();
};
