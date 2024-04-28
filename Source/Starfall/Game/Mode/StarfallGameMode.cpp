// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarfallGameMode.h"
#include "../../Character/StarfallCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStarfallGameMode::AStarfallGameMode()
{
	// set default pawn class to our Blueprinted character
	//	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Hero/BP_StarfallHeroCharacter"));
	//	if (PlayerPawnBPClass.Class != NULL)
	//	{
	//		DefaultPawnClass = PlayerPawnBPClass.Class;
	//	}
	// Set default controller class to our Blueprinted controller
	//	static ConstructorHelpers::FClassFinder<AController> PlayerControllerBPClass(TEXT("/Game/Characters/Hero/BP_StarfallHeroController"));
	//	if (PlayerControllerBPClass.Class != nullptr) // Ensuring the Blueprint class is found
	//	{
	//		DefaultControllerClass = PlayerControllerBPClass.Class;
	//	}
}	//	
