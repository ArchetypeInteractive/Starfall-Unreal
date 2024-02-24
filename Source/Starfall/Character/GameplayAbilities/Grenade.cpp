// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"

void UGrenade::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    AActor* OwningActor = GetOwningActorFromActorInfo();
    if (OwningActor)
    {
        // Spawn and throw the grenade
        FVector SpawnLocation = OwningActor->GetActorLocation() + OwningActor->GetActorForwardVector() * 100.0f; // Example spawn location
        FRotator SpawnRotation = OwningActor->GetActorRotation(); // Example spawn rotation

        float Velocity = 0.f;
        AActor* Grenade = GetWorld()->SpawnActor<AActor>(SpawnLocation, SpawnRotation);
        if (Grenade)
        {
            //  Apply velocity to simulate throwing the grenade
            FVector Direction = OwningActor->GetActorForwardVector(); // Example throw direction
            //  We need to grab the control rig and makes changes
            //  Or use static animation
            //  then launch the projectile 
            this->Throw(Grenade, Direction, Velocity);
        }
    }
}


void UGrenade::Throw(AActor* Projectile, FVector Direction, float Velocity)
{
    UE_LOG(LogTemp, Display, TEXT("Throwing"))
}