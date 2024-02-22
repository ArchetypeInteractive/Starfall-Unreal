// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallHeroCharacter.h"



AStarfallHeroCharacter::AStarfallHeroCharacter()
{
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom (pulls in towards the player if there is a collision)
	//	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//	CameraBoom->SetupAttachment(GetMesh(), "head");
	//	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	//	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh(), "head"); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm
	FollowCamera->SetRelativeLocation(FVector(8.0f, 14.0f, 0.f));
	FollowCamera->SetRelativeRotation(FRotator(180.0f, -90.0f, 90.0f));
	FollowCamera->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
}