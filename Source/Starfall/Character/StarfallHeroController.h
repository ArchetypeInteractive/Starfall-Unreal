// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "GameFramework/PlayerController.h"
#include "StarfallHeroController.generated.h"

/**
 * 
 */




UCLASS()
class STARFALL_API AStarfallHeroController : public APlayerController
{
	GENERATED_BODY()
	

public:
	AStarfallHeroController();


	virtual void BeginPlay() override;

	// Define the delegate

};
