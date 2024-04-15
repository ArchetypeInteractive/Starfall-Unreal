// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystemInterface.h"
#include <EnhancedInputSubsystems.h>
#include "StarfallHeroController.generated.h"

//	----------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnStatusChangeDelegate);

//	----------------------------

UCLASS()
class STARFALL_API AStarfallHeroController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = Preferences )
	float LookSpeed = 1;

protected:
	virtual void BeginPlay() override;

public:
	AStarfallHeroController();
	FPawnStatusChangeDelegate PawnStatusChange;


	void NotifyPossessionChanging() {
		PawnStatusChange.Broadcast();
	}



	virtual void SetupInputComponent() override;
	
	
	UFUNCTION()
	void HandlePawnPossessed();
	UFUNCTION()
	void HandlePawnUnPossessed();

	void SwitchInputContext(UInputMappingContext* NewContext, int32 Priority);

	UEnhancedInputLocalPlayerSubsystem* Subsystem;
	UEnhancedInputComponent* EnhancedInputComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* UIContext;


	/** Jump Input Action */
	/** Move Input Action */
	/** Look Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* WeaponAction;
	*/
	


	//	----------------------------


	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);


	void SetMappingContext(UInputMappingContext* Context);

	//	void SetEnhancedInputComponent(UEnhancedInputComponent* EnhancedInputComponent);
	UEnhancedInputComponent* GetEnhancedInputComponent() const { return EnhancedInputComponent; };
};