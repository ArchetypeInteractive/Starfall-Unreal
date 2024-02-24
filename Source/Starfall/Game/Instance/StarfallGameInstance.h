// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StarfallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API UStarfallGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UStarfallGameInstance();


	virtual void Init() override;
};
