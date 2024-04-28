// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Starfall/Game/Instance/UI/UserInterfaceWindow.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserInterfaceWindow> BlueprintWindowClass;


	virtual void Init() override;
	void NakamaSubsystem();

	void UISubsystem();
};
