// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarfallCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"

//	DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AStarfallCharacter

AStarfallCharacter::AStarfallCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UStarfallMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));



	// Create and assign the custom movement component
	//	StarfallMovementComponent = CreateDefaultSubobject<UStarfallMovementComponent>(TEXT("CustomMovementComp"));
	//	Set this as the character's primary movement component
	//	Super::SetMovementComponent(StarfallMovementComponent);


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
	GetCharacterMovement()->CrouchedHalfHeight = 50.f;

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
		Yaw = Value.X;
		Pitch = Value.Y;
		AddControllerYawInput(Value.X * 2);
		AddControllerPitchInput(Value.Y * 2);

		//	------------
		OnCharacterLooked.Broadcast();
	}
}



void AStarfallCharacter::Jump()
{
	Super::Jump();
	UE_LOG(LogTemp, Warning, TEXT("Character is jumping"))
		//	OnCharacterStoppedJumping.Broadcast();
}
void AStarfallCharacter::StopJumping()
{
	Super::StopJumping();
	UE_LOG(LogTemp, Warning, TEXT("Character stopped jumping"))
	//	OnCharacterStoppedJumping.Broadcast();
}


void AStarfallCharacter::Sprint()
{
	UE_LOG(LogTemp, Warning, TEXT("Sprinting"))
	//	OnCharacterSprinted.Broadcast();
}


void AStarfallCharacter::StopSprinting()
{
	UE_LOG(LogTemp, Warning, TEXT("Stopped Sprinting"))
}



void AStarfallCharacter::Crouch() { GetCharacterMovement()->Crouch(true); }
void AStarfallCharacter::UnCrouch() { GetCharacterMovement()->UnCrouch(true); }



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