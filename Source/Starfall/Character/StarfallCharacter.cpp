// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarfallCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameplayAbilities/Grenade.h"

//	DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AStarfallCharacter

AStarfallCharacter::AStarfallCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));


	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AStarfallCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	//	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	//	{
	//		SetupAbilitySystem();
	//	}
}

//////////////////////////////////////////////////////////////////////////
// Input
/*
void AStarfallCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//	Set up action bindings
	//	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
	//		
	//		// Jumping
	//		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
	//		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	//	
	//		// Moving
	//		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStarfallCharacter::Move);
	//	
	//		// Looking
	//		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AStarfallCharacter::Look);
	//		
	//		EnhancedInputComponent->BindAction(GrenadeAction, ETriggerEvent::Started, this, &AStarfallCharacter::ThrowGrenade);
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	//	}
}
*/

void AStarfallCharacter::Move(FVector2D Value)
{
	

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Value.Y);
		AddMovementInput(RightDirection, Value.X);


		OnCharacterMoved.Broadcast();
	}
}


void AStarfallCharacter::Look(FVector2D Value)
{
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Value.X);
		AddControllerPitchInput(Value.Y);

		//	------------
		OnCharacterLooked.Broadcast();
	}
}



void AStarfallCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (NewController)
	{
		FString ControllerName = NewController->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Possessed by %s"), *ControllerName)
		OnPawnPossessed.Broadcast();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Possessed by unknown controller"));
	}
}

void AStarfallCharacter::UnPossessed()
{
	UE_LOG(LogTemp, Display, TEXT("Unpossessed!"));

	OnPawnUnPossessed.Broadcast();
}


/*
void AStarfallCharacter::SetupAbilitySystem()
{
	if (AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Setting up ability system!"))
		//	// Set up ability system component replication
		//	AbilitySystemComponent->SetIsReplicated(true);
		//	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No ability system"))
	}
}


void AStarfallCharacter::ThrowGrenade()
{
	if (AbilitySystemComponent)
	{
		//	if (UGameplayAbility* Grenade = UGameplayAbility::StaticClass()->GetDefaultObject<UGrenade>())
		UE_LOG(LogTemp, Display, TEXT("Throwing Grenade!"));
	}
}
*/