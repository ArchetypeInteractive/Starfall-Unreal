// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallVendorCharacter.h"

AStarfallVendorCharacter::AStarfallVendorCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("Vendor spawned"))
}


void AStarfallVendorCharacter::BeginPlay()
{
	FGameplayTag NewTag = FGameplayTag::RequestGameplayTag(FName(*MyTag.ToString()));
	ActorTags.AddTag(NewTag);
}