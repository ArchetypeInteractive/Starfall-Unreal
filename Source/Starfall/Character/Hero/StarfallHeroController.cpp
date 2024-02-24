// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallHeroController.h"
#include "Starfall/Game/Instance/UI/UserInterfaceSubsystem.h"

AStarfallHeroController::AStarfallHeroController()
{
	UE_LOG(LogTemp, Display, TEXT("Player controller stuff"))




	//	Enhanced Input Actions go here?
}

void AStarfallHeroController::BeginPlay()
{
	Super::BeginPlay();




    //  This should go in our actual game instance
    //  But I suppose it's fine for right now
    // 
    // 
    //  Access the Game Instance
    //  UGameInstance* GameInstance = GetGameInstance();
    //  if (GameInstance != nullptr)
    //  {
    //      // Replace 'YourUserInterfaceSubsystem' with the actual name of your subsystem class
    //      // And replace 'GetSubsystem<YourUserInterfaceSubsystem>()' with the correct method to get your subsystem
    //      UUserInterfaceSubsystem* UISubsystem = GameInstance->GetSubsystem<UUserInterfaceSubsystem>();
    //      if (UISubsystem != nullptr)
    //      {
    //          // Now you can call any public method on your UI subsystem, like the event to mount the UI
    //          UISubsystem->CreateAndDisplayUI();
    //      }
    //  }
}