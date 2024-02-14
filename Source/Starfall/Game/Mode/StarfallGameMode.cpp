// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarfallGameMode.h"
#include "../../Character/StarfallCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStarfallGameMode::AStarfallGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Hero/BP_StarfallHeroCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
