// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallEnemyCharacter.h"
#include "StarfallEnemyController.h"

AStarfallEnemyCharacter::AStarfallEnemyCharacter(const FObjectInitializer& ObjectInitializer) : AStarfallCharacter(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy spawned"))

	Radar = CreateDefaultSubobject<URadarComponent>(TEXT("Radar"));
	AIControllerClass = AStarfallEnemyController::StaticClass();
}


void AStarfallEnemyCharacter::BeginPlay()
{
	//	FGameplayTag NewTag = FGameplayTag::RequestGameplayTag(FName(*MyTag.ToString()));
	//	ActorTags.AddTag(NewTag);
}


