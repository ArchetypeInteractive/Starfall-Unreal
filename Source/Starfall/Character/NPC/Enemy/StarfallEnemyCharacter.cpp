// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallEnemyCharacter.h"

AStarfallEnemyCharacter::AStarfallEnemyCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy spawned"))
}


void AStarfallEnemyCharacter::BeginPlay()
{
	FGameplayTag NewTag = FGameplayTag::RequestGameplayTag(FName(*MyTag.ToString()));
	ActorTags.AddTag(NewTag);
}