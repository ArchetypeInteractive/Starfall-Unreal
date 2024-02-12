// Fill out your copyright notice in the Description page of Project Settings.


#include "NakamaSubsystem.h"


void UNakamaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Display, TEXT("NAKAMA SUBSYSTEM GO VROOM"));
}



void UNakamaSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Display, TEXT("De-initializing NAKAMA SUBSYSTEM"));
}