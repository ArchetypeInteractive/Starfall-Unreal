// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Starfall/Character/StarfallCharacter.h"
#include "Starfall/Weapon/StarfallWeapon.h"
#include "ArsenalComponent.generated.h"


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

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* WeaponInputContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* AimAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* FireAction;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	TSubclassOf<AStarfallWeapon> Weapon;





	void Aim(const FInputActionValue& Value);
	void Fire(const FInputActionValue& Value);

	AStarfallWeapon* GetActiveWeapon() const { return Cast<AStarfallWeapon>(Weapon); }
};
