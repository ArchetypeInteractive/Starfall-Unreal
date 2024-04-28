// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallWeaponAbility.h"

UStarfallWeaponAbility::UStarfallWeaponAbility()
{
	Damage = 20.0f;
	Cooldown = 1.f;
	Ammo = 30;

}



void UStarfallWeaponAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	UE_LOG(LogTemp, Warning, TEXT("Firing!"))
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo)) { EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true); }

	//	Firing logic

}



void UStarfallWeaponAbility::SpawnWeapon(AStarfallCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning Weapon mesh and attaching to character!"))
	//	WeaponMesh->AttachToComponent(Character->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}