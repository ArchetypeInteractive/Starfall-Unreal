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

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterMovedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterLookedDelegate);

UCLASS(config=Game)
class AStarfallCharacter : public ACharacter
{
	GENERATED_BODY()

	//	/** Camera boom positioning the camera behind the character */
	//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//	USpringArmComponent* CameraBoom;
	//	
	//	/** Follow camera */
	//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* GrenadeAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AStarfallCharacter();

	// Gameplay Tag Container for this actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer ActorTags;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	FGameplayTag MyTag;
	
	FOnCharacterMovedDelegate OnCharacterMoved;
	FOnCharacterLookedDelegate OnCharacterLooked;
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();



	UPROPERTY()
	class UAbilitySystemComponent* AbilitySystemComponent; // Ability System Component reference




public:
	//	/** Returns CameraBoom subobject **/
	//	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//	/** Returns FollowCamera subobject **/
	//	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	void SetupAbilitySystem();
	void ThrowGrenade();





};

