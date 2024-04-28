// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallGameInstance.h"
#include "UI/UserInterfaceSubsystem.h"
#include <Kismet/GameplayStatics.h>
#include <Starfall/Character/Hero/StarfallHeroController.h>

UStarfallGameInstance::UStarfallGameInstance()
{

}


void UStarfallGameInstance::Init()
{
    Super::Init();  // Ensure to call the base class Init to properly initialize inherited aspects.

    AStarfallHeroController* Controller = Cast<AStarfallHeroController>(UGameplayStatics::GetPlayerController(this, 0));
    if (Controller)
    {
        //  Bind to the controller's OnControllerReady event
        UE_LOG(LogTemp, Warning, TEXT("Found player controller in game instance!"))
        //  Controller->OnControllerReady.AddDynamic(this, &UStarfallGameInstance::UISubsystem);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player controller not found. UI Subsystem initialization deferred."));
        // Optionally, setup a retry mechanism or handle in tick/update if the controller might be later available
    }
}


void UStarfallGameInstance::NakamaSubsystem()
{
    UE_LOG(LogTemp, Warning, TEXT("Setting up Nakama!!"))
}

void UStarfallGameInstance::UISubsystem()
{
    UE_LOG(LogTemp, Warning, TEXT("StarfallGameInstance::Init() - Game Instance Loaded"));

    UUserInterfaceSubsystem* Subsystem = GetSubsystem<UUserInterfaceSubsystem>();
    if (Subsystem)
    {
        UE_LOG(LogTemp, Warning, TEXT("StarfallGameInstance::Init() - UserInterfaceSubsystem is valid and will attempt to create and display UI."));
        //  Subsystem->CreateAndDisplayUI();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("StarfallGameInstance::Init() - Failed to retrieve UserInterfaceSubsystem."));
    }
}