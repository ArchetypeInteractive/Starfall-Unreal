// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Starfall/Character/StarfallCharacter.h"
#include "Starfall/Character/Hero/StarfallHeroController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Starfall/Character/Components/ArsenalComponent.h"
#include "StarfallHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;


/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallHeroCharacter : public AStarfallCharacter
{
	GENERATED_BODY()

protected:

	virtual void PossessedBy(AController* NewController) override;


public:

	AStarfallHeroCharacter();



	AStarfallHeroController* StarfallController;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Radar, meta = (AllowPrivateAccess = "true"))
	URadarComponent* Radar;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Radar, meta = (AllowPrivateAccess = "true"))
	UArsenalComponent* Arsenal;




	//	/** Camera boom positioning the camera behind the character */
	//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//	USpringArmComponent* CameraBoom;
	//	
	//	/** Follow camera */
	//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//	UCameraComponent* FollowCamera;

	/** Jump Input Action */
	/** Jump Input Action */
	/** Move Input Action */
	/** Look Input Action */
	/** MappingContext 
	* 
	* 
	* 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* PawnInputContext;




protected:
	virtual void BeginPlay() override;
	//	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	URadarComponent* GetRadarComponent() const
	{
		return Cast<URadarComponent>(GetComponentByClass(URadarComponent::StaticClass()));
	}


	virtual void InputLook(const FInputActionValue& Value);
	virtual void InputMove(const FInputActionValue& Value);

	virtual void Jump() override;
	virtual void StopJumping() override;



	/*
	void Jump();
	void StopJump();
	void Aim(FVector3d Value);
	void WeaponAction();
	*/
};
