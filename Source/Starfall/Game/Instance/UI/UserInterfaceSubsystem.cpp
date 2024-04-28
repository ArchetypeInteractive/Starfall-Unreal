#include "UserInterfaceSubsystem.h"
#include "Starfall/Character/Hero/StarfallHeroController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"



void UUserInterfaceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Warning, TEXT("UI Subsystem init"))
    
    //  OnUIMountedSuccess.AddDynamic(this, &UUserInterfaceSubsystem::Display);
}

UUserInterfaceWindow* UUserInterfaceSubsystem::Mount()
{
    if (UIWindow) {
        UE_LOG(LogTemp, Error, TEXT("UI Window already mounted"));
        return UIWindow;
    }

    AStarfallHeroController* Controller = Cast<AStarfallHeroController>(UGameplayStatics::GetPlayerController(this, 0));
    if (Controller)
    {
        UIWindow = CreateWidget<UUserInterfaceWindow>(Controller, UUserInterfaceWindow::StaticClass());
        if (UIWindow)
        {
            UIWindow->SetVisibility(ESlateVisibility::Visible); // Set visibility right after creation
            OnUISuccess.Broadcast();
            UE_LOG(LogTemp, Log, TEXT("UI Window successfully created and ready to mount"));
            return UIWindow;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to create UI Window"));
            OnUIError.Broadcast();
            return nullptr;
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Player controller not found"));
        OnUIError.Broadcast();
        return nullptr;
    }
}
//  ------------




UCommonActivatableWidgetStack* UUserInterfaceSubsystem::GetUILayer(FGameplayTag Tag)
{
    UCommonActivatableWidgetStack* LayerPtr = Cast<UUserInterfaceWindow>(UIWindow)->GetUIWindowLayer(Tag);
    // GetUILayers.Find(Tag);  // Find the layer by tag

    // Log the retrieval attempt
    if (LayerPtr)
    {
        //  UE_LOG(LogTemp, Warning, TEXT("Layer found: %s"), *Tag.ToString());
        return LayerPtr;  // Return the found layer
    }
    else
    {
        //  UE_LOG(LogTemp, Warning, TEXT("No layer found with tag: %s"), *Tag.ToString());
        return nullptr;  // Return nullptr if not found
    }
}
