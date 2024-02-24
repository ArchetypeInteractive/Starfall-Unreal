#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Starfall/Game/Instance/Nakama/NakamaSubsystem.h"
#include "NakamaUnreal.h"
#include "NakamaClient.h"
#include "NakamaSession.h"
#include "NakamaRealtimeClient.h"
#include "QuestSubsystem.generated.h"

UENUM(BlueprintType)
enum class ERarity : uint8
{
    Common,
    Rare,
    Legendary,
    Exotic
};

USTRUCT(BlueprintType)
struct FQuestObjective
{
    GENERATED_BODY()

    FName ObjectiveName;
    FString ObjectiveDescription;
    bool bIsCompleted;
};


USTRUCT(BlueprintType)
struct FQuestData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestID; // Unique identifier for quests

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ERarity QuestRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FQuestObjective> Objectives;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredLevel;
};





UCLASS(BlueprintType)
class STARFALL_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()



public:

    void Initialize(FSubsystemCollectionBase& Collection);

    //  UNakamaSession = NakamaSubsystem<Session>



    void AddQuest(const FQuestData& NewQuest );
    void UpdateQuestObjective(const FString& QuestID, const FString& ObjectiveDescription, int32 ProgressAmount);
    void DiscardQuest(const FQuestData& Quest);


    UFUNCTION()
	void FetchQuests(UNakamaSession* Session);

    //  UFUNCTION(Server, Reliable, WithValidation)
    //  void PushQuests(const FQuestData& Quest);
};
