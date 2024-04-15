// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallHeroCharacter.h"
#include "StarfallHeroController.h"
#include <EnhancedInputComponent.h>



AStarfallHeroCharacter::AStarfallHeroCharacter()
{
	//	Define our mapping context for our player
	//	Define our input actions?



	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	  

	//	Create a camera boom (pulls in towards the player if there is a collision)
	//	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//	CameraBoom->SetupAttachment(GetMesh(), "head");
	//	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	//	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller


	//	Radar = CreateDefaultSubobject<URadarComponent>(TEXT("Radar"));
	Arsenal = CreateDefaultSubobject <UArsenalComponent>(TEXT("Arsenal"));
	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh(), "head"); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm
	FollowCamera->SetRelativeLocation(FVector(8.0f, 14.0f, 0.f));
	FollowCamera->SetRelativeRotation(FRotator(180.0f, -90.0f, 90.0f));
	FollowCamera->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
}


void AStarfallHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	StarfallController = Cast<AStarfallHeroController>(GetController());
	if (StarfallController)
	{
	}
}




void AStarfallHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	UE_LOG(LogTemp, Warning, TEXT("Possessed log from Hero Character!"))

	// We'll send our Input Context and Actions to controller here!
	AStarfallHeroController* HeroController = Cast<AStarfallHeroController>(NewController);
	if (HeroController)
	{
		UEnhancedInputComponent* EnhancedInputComponent = HeroController->GetEnhancedInputComponent();
		if (EnhancedInputComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("Enhanced Input confirmed"))
			//	Setup the context
			//	UInputMappingContext* MyInputContext = CreateInputContext(); // You need to implement this
			HeroController->SwitchInputContext(PawnInputContext, 0); // Assumes priority 1

			//	Bind actions
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AStarfallHeroCharacter::InputLook);
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStarfallHeroCharacter::InputMove);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AStarfallHeroCharacter::Jump);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AStarfallHeroCharacter::StopJumping);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
		}
	}
}


void AStarfallHeroCharacter::InputLook(const FInputActionValue& Value)
{

	//	------------------------
	//	Pass our player's input into parent's look method
	
	FVector2D Direction = Value.Get<FVector2D>();
	Look(Direction);

	//	UE_LOG(LogTemp, Warning, TEXT("Looking!"))

	//	------------------------
	//	
	//	float Right = Value.X;
	//	float Up = Value.Y;
	//	AddControllerYawInput(Right * Velocity * GetWorld()->GetDeltaSeconds());
	//	AddControllerPitchInput(Up * Velocity * GetWorld()->GetDeltaSeconds());
}


void AStarfallHeroCharacter::InputMove(const FInputActionValue& Value)
{
	//	UE_LOG(LogTemp, Warning, TEXT("Input move recognized"))
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	Move(MovementVector);
}



void AStarfallHeroCharacter::Jump()
{
	Super::Jump();
}


void AStarfallHeroCharacter::StopJumping()
{
	Super::StopJumping();
}