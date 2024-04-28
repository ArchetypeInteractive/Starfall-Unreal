// Fill out your copyright notice in the Description page of Project Settings.


#include "ArsenalComponent.h"
#include "AbilitySystemComponent.h"
#include <Starfall/Character/Hero/StarfallHeroCharacter.h>
#include <EnhancedInputComponent.h>


// Sets default values for this component's properties
UArsenalComponent::UArsenalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//  PrimaryComponentTick.bCanEverTick = true;
    this->bAutoActivate = true;
	// ...
}


void UArsenalComponent::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Arsenal Component begin play"))

    AStarfallCharacter* Celestial = Cast<AStarfallCharacter>(GetOwner());
    if (!Celestial)
    {
        UE_LOG(LogTemp, Warning, TEXT("Celestial not defined"))

        if (!PrimaryWeapon) {
            UE_LOG(LogTemp, Warning, TEXT("Primary weapon not defined"))
        }
    }

    Cast<UStarfallWeaponAbility>(PrimaryWeapon)->SpawnWeapon(Cast<AStarfallCharacter>(GetOwner()));

    //  AbilitySystem - Ability;
}


void UArsenalComponent::SwitchWeapon(EWeaponSlots* Slot)  //  SwitchWeapon(UStarfallWeaponAbility Weapon)
{
    UE_LOG(LogTemp, Warning, TEXT("Switching weapons!"))

    //  1.  clear previously granted gameplay ability
    //  AbilitySystem->ClearAbility();
    //  Ability = nullptr;
    //      a.  Broadcast event
    // 
    //  2.  play weapon swapping animation
    // 
    //  3.  grant new weapon's gameplay ability
    //  
}









/*
// Called when the game starts
void UArsenalComponent::BeginPlay()
{
    Super::BeginPlay();

    if (GetOwner())
    {
        AStarfallHeroCharacter* OwnerCharacter = Cast<AStarfallHeroCharacter>(GetOwner());
        if (OwnerCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("Confirmed hero character is owner! Next, check for controller"))


                /*
                //  We can probably move this stuff to AStarfallWeapon, to give each weapon the opportunity to override.
                //  Downside would be that we'd have to specify each action for each weapon in each blueprint.
                //  Could that be bypassed by just inheriting from BP_StarfallWeapon?
                
                AStarfallHeroController* OwnerController = Cast<AStarfallHeroController>(OwnerCharacter->GetController());
                if (OwnerController)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Controller confirmed! Now lets add our inputs"))
                        UEnhancedInputComponent* EnhancedInputComponent = OwnerController->GetEnhancedInputComponent();
                        if (EnhancedInputComponent)
                        {
                            UE_LOG(LogTemp, Warning, TEXT("Enhanced Input confirmed"))
                                //	Setup the context
                                //	UInputMappingContext* MyInputContext = CreateInputContext(); // You need to implement this
                                OwnerController->SwitchInputContext(WeaponInputContext, 1); // Assumes priority 1

                            //	Bind actions
                            EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &UArsenalComponent::Aim);
                            EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UArsenalComponent::Fire);
                        }
                            else {
                                UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
                            }
                        }
                    
                }
        }


        if (Weapon) // Check if the Weapon class is set
        {
            UE_LOG(LogTemp, Warning, TEXT("Weapon class is set"))
            FActorSpawnParameters SpawnParams;
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        
            // Spawn the weapon at the owner's location
            AStarfallWeapon* SpawnedWeapon = GetWorld()->SpawnActor<AStarfallWeapon>(Weapon, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
            if (SpawnedWeapon)
            {
                UE_LOG(LogTemp, Warning, TEXT("spawned weapon is set"))
                //  Immediately disable physics to prevent unwanted interactions
                SpawnedWeapon->GetMesh()->SetSimulatePhysics(false);
                SpawnedWeapon->GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        
                // Adjust attachment rules here to include the socket's rotation
                FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
        
                // Attach the spawned weapon to the 'ik_hand_r' socket of the owner's mesh
                SpawnedWeapon->AttachToComponent(Cast<ACharacter>(GetOwner())->GetMesh(), AttachmentRules, TEXT("ik_hand_r"));
        
                // Optionally, after attachment, set collision to ignore pawn to prevent physics-based movement issues
                SpawnedWeapon->GetMesh()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
            }
            else {
                UE_LOG(LogTemp, Warning, TEXT("No spawned weapon :("))
            }
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("Weapon class is not set"))
        }
    }
}


// Called every frame
void UArsenalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}




void UArsenalComponent::Aim(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Aiming weapon"))
}


void UArsenalComponent::Fire(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Firing weapon"))
}

*/



