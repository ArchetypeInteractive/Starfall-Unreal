// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallCelestial.h"
#include "AbilitySystemComponent.h"

AStarfallCelestial::AStarfallCelestial(const FObjectInitializer& ObjectInitializer) : AStarfallCharacter(ObjectInitializer)
{
    //	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
		// Initialize the Ability System Component
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}


void AStarfallCelestial::SetupAbilitySystem()
{
	if (AbilitySystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Setting up ability system!"))
		//	AbilitySystemComponent->SetIsReplicated(true);
		//	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No ability system"))
	}
}




/*


void AStarfallCharacter::ThrowGrenade()
{
	if (AbilitySystemComponent)
	{
		//	if (UGameplayAbility* Grenade = UGameplayAbility::StaticClass()->GetDefaultObject<UGrenade>())
		UE_LOG(LogTemp, Display, TEXT("Throwing Grenade!"));
	}
}
*/