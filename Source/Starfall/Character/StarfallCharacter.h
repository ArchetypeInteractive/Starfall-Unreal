// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Logging/LogMacros.h"
#include "Components/StarfallMovementComponent.h"
#include "StarfallCharacter.generated.h"


/*
*/
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;



//	DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

//	POSSESSION	-----
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnPossessedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnUnPossessedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterMovedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterLookedDelegate);


//	----
//	
//	----

UCLASS(config=Game)
class AStarfallCharacter : public ACharacter
{
	GENERATED_BODY()

protected:


			
	/** Called for looking input */
	//	APawn interface
	// To add mapping context
	//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay();
	virtual void UnPossessed() override;
	virtual void PossessedBy(AController* NewController) override;



	//	UPROPERTY()
	//	class UAbilitySystemComponent* AbilitySystemComponent; // Ability System Component reference



public:
	AStarfallCharacter(const FObjectInitializer& ObjectInitializer);

	// Gameplay Tag Container for this actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer ActorTags;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	FGameplayTag MyTag;
	




	//	----------------------------------------
	//	EVENT DELEGATES
	//	----------------------------------------
	FOnPawnPossessedDelegate OnPawnPossessed;
	FOnPawnUnPossessedDelegate OnPawnUnPossessed;
	FOnCharacterMovedDelegate OnCharacterMoved;
	FOnCharacterLookedDelegate OnCharacterLooked;
	//	----------------------------------------



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look")
	float Yaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look")
	float Pitch;










	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UStarfallMovementComponent* StarfallMovementComponent;
	//	/** Returns CameraBoom subobject **/
	//	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//	/** Returns FollowCamera subobject **/
	//	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	//	void SetupAbilitySystem();
	//	void ThrowGrenade();
	
	/** Called for movement input */
	void Move(FVector2D Value);
	virtual void Sprint();
	virtual void StopSprinting();
	void Look(FVector2D Value);



	virtual void Jump() override;
	virtual void StopJumping() override;
	virtual void Crouch();
	virtual void UnCrouch();
};