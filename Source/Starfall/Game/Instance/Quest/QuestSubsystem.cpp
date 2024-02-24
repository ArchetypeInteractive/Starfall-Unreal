// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"





void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UGameInstance* GameInstance = GetGameInstance();
    if (GameInstance)
    {
        UNakamaSubsystem* NakamaSubsystem = GameInstance->GetSubsystem<UNakamaSubsystem>();
        if (NakamaSubsystem)
        {
            NakamaSubsystem->AuthenticationSuccessDelegate.AddDynamic(this, &UQuestSubsystem::FetchQuests);
        }
    }
}



void UQuestSubsystem::AddQuest(const FQuestData& NewQuest)
{
	UE_LOG(LogTemp, Display, TEXT("Add Quest"));
}

void UQuestSubsystem::UpdateQuestObjective(const FString& QuestID, const FString& ObjectiveDescription, int32 ProgressAmount)
{
	UE_LOG(LogTemp, Display, TEXT("Updating Quest Objective"));
}

void UQuestSubsystem::DiscardQuest(const FQuestData& Quest)
{
	UE_LOG(LogTemp, Display, TEXT("Discarding quest!"));
}







void UQuestSubsystem::FetchQuests(UNakamaSession* Session)
{
    UE_LOG(LogTemp, Display, TEXT("Logging Fetch Quests from the server"));
}