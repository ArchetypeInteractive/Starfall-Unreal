// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include <Starfall/Character/StarfallCharacter.h>
#include "StarfallWeaponAbility.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API UStarfallWeaponAbility : public UGameplayAbility
{
	GENERATED_BODY()


	UStarfallWeaponAbility();

	void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);


	float Damage;
	float Cooldown;
	float Ammo;




public:
	// In your GameplayAbility subclass
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

	void SpawnWeapon(AStarfallCharacter* Character);

	//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	//	UAnimMontage* FireAnimation;

};
