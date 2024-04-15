#include "StarfallHeroController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "StarfallHeroCharacter.h"

AStarfallHeroController::AStarfallHeroController()
{
    UE_LOG(LogTemp, Display, TEXT("Player controller stuff"));
}


void AStarfallHeroController::BeginPlay()
{
    Super::BeginPlay();

    if (GetLocalPlayer())
    {
        //  ----
        Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
        UE_LOG(LogTemp, Display, TEXT("Testing here"));

        if (Subsystem) { 
            UE_LOG(LogTemp, Warning, TEXT("Subsystem found in Controller, what the hell"))
            
            
            if (UIContext != nullptr) { SwitchInputContext(UIContext, 0); }
            
            AStarfallCharacter* StarfallCharacter = Cast<AStarfallCharacter>(GetPawn());

            if (StarfallCharacter)
            {
                UE_LOG(LogTemp, Warning, TEXT("Testing character?"))
                StarfallCharacter->OnPawnPossessed.AddDynamic(this, &AStarfallHeroController::HandlePawnPossessed);
                StarfallCharacter->OnPawnUnPossessed.AddDynamic(this, &AStarfallHeroController::HandlePawnUnPossessed);
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Subsystem not found."));
        }
    }
}


void AStarfallHeroController::SetupInputComponent()
{
    Super::SetupInputComponent();
    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    if (EnhancedInputComponent)
    {

    }
}


void AStarfallHeroController::SwitchInputContext(UInputMappingContext* NewContext, int32 Priority)
{
    if (GetLocalPlayer())
    {
        UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
        if (PlayerSubsystem)
        {
            UE_LOG(LogTemp, Warning, TEXT("Clearing out mappings and setting new context"));
            // Clear the current context to avoid overlaps
            //  PlayerSubsystem->ClearAllMappings();

            // Add the new context with the specified priority
            PlayerSubsystem->AddMappingContext(NewContext, Priority);

        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("No subsystem found :("))
        }
    }
}





void AStarfallHeroController::HandlePawnPossessed()
{
    //  UE_LOG(LogTemp, Warning, TEXT("possess from controller???"))

    //  this may be removed, we shouldn't need to do anything after possession? unless we want to do something with nakama!
}


void AStarfallHeroController::HandlePawnUnPossessed()
{
    UE_LOG(LogTemp, Warning, TEXT("Unpossessed from controller???"))

    //  SwitchInputContext(UIContext, 0);
}