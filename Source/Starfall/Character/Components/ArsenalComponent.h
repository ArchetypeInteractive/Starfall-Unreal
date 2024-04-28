// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.h"
#include <Starfall/Character/GameplayAbilities/StarfallWeaponAbility.h>
#include "ArsenalComponent.generated.h"





UENUM(BlueprintType)
enum EWeaponSlots
{
	Primary		UMETA(DisplayName = "Primary"),
	Special		UMETA(DisplayName = "Special"),
	Heavy		UMETA(DisplayName = "Heavy")
};





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFALL_API UArsenalComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArsenalComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//	UPROPERTY(EditAnywhere, Category = "Input")
	//	UInputMappingContext* WeaponInputContext;
	//	
	//	UPROPERTY(EditAnywhere, Category = "Input")
	//	UInputAction* AimAction;
	//	
	//	UPROPERTY(EditAnywhere, Category = "Input")
	//	UInputAction* FireAction;



public:	
	// Called every frame
	//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	//	TSubclassOf<AStarfallWeapon> Weapon;


	UAbilitySystemComponent* AbilitySystem;

	void SetAbilitySystemComponent(UAbilitySystemComponent* AbilitySystemComponent) { AbilitySystem = AbilitySystemComponent; };



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UStarfallWeaponAbility> PrimaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UStarfallWeaponAbility> SpecialWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UStarfallWeaponAbility> HeavyWeapon;


	void SwitchWeapon(EWeaponSlots* Slot);



	UGameplayAbility* Ability;

	//	void Aim(const FInputActionValue& Value);
	//	void Fire(const FInputActionValue& Value);

	//	AStarfallWeapon* GetActiveWeapon() const { return Cast<AStarfallWeapon>(Weapon); }
};
