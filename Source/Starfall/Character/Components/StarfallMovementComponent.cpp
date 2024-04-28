// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallMovementComponent.h"
#include <Starfall/Character/StarfallCharacter.h>
//	#include "CharacterTrajectoryComponent.h"



void UStarfallMovementComponent::Crouch(bool bClientSimulation)
{
	Super::Crouch(bClientSimulation);
	UE_LOG(LogTemp, Warning, TEXT("Crouching from Custom Movement Component!"))


}



void UStarfallMovementComponent::Init()
{
	AStarfallCharacter* Owner = Cast<AStarfallCharacter>(GetOwner());
	if (Owner)
	{
		//	UCharacterTrajectoryComponent* Trajectory = CreateDefaultSubobject<UCharacterTrajectoryComponent>(TEXT("TrajectoryComponent"));
		//	Trajectory->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	}
}



void UStarfallMovementComponent::Sliding()
{
	UE_LOG(LogTemp, Warning, TEXT("Sliding"))
}