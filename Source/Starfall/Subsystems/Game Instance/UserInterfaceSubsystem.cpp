// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceSubsystem.h"
#include "../../Character/StarfallHeroController.h" // Adjust the include path to your player controller
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"


void UUserInterfaceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    //  Attempt to bind to the player controller's initialized event
    //  OnUIReadyToMount.AddDynamic(this, &UUserInterfaceSubsystem::OnLevelLoaded);
}


//  We call this function from our GameInstance, so our UI is created *AFTER* our world
void UUserInterfaceSubsystem::CreateAndDisplayUI()
{
    UE_LOG(LogTemp, Display, TEXT("USERINTERFACE_SUBSYSTEM HAS DETECTED A PLAYER CONTROLLER"))
    
    
    if (UIWindow != nullptr) return;    // If UIWindow has already been defined, SKIP


    AStarfallHeroController* Controller = Cast<AStarfallHeroController>(GetGameInstance()->GetFirstLocalPlayerController(GetWorld()));
    
    UIWindow = CreateWidget<UUserInterfaceWindow>(Controller, UUserInterfaceWindow::StaticClass());

    if (Controller)
    {
        //  Controller exists

        if (UIWindow)
        {
            UE_LOG(LogTemp, Display, TEXT("Setting up UI Window"));
            UIWindow->AddToViewport();

            OnWindowUILoadSuccess.Broadcast();
        }
        else {
            UE_LOG(LogTemp, Display, TEXT("Failed to set up UI Window"));
            OnWindowUILoadError.Broadcast();
        }
    }
}


void UUserInterfaceSubsystem::UITestMethod()
{
    UE_LOG(LogTemp, Display, TEXT("Testtttt"))
}
