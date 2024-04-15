// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Components/RadarComponent.h"
#include "Logging/LogMacros.h"
#include "StarfallCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;



//	DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

//	POSSESSION	-----
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnPossessedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnUnPossessedDelegate);

//	----
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterMovedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterLookedDelegate);

UCLASS(config=Game)
class AStarfallCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStarfallCharacter();

	// Gameplay Tag Container for this actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer ActorTags;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	FGameplayTag MyTag;
	

	FOnPawnPossessedDelegate OnPawnPossessed;
	FOnPawnUnPossessedDelegate OnPawnUnPossessed;
	FOnCharacterMovedDelegate OnCharacterMoved;
	FOnCharacterLookedDelegate OnCharacterLooked;
protected:

	/** Called for movement input */
	void Move(FVector2D Value);
	void Look(FVector2D Value);

	/** Called for looking input */
			
	//	APawn interface
	//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();


	virtual void UnPossessed() override;
	virtual void PossessedBy(AController* NewController) override;



	//	UPROPERTY()
	//	class UAbilitySystemComponent* AbilitySystemComponent; // Ability System Component reference




public:
	//	/** Returns CameraBoom subobject **/
	//	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//	/** Returns FollowCamera subobject **/
	//	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	//	void SetupAbilitySystem();
	//	void ThrowGrenade();
};

