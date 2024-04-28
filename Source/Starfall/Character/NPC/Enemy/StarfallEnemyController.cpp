// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallEnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"


AStarfallEnemyController::AStarfallEnemyController()
{
}


void AStarfallEnemyController::BeginPlay()
{
    UE_LOG(LogTemp, Warning, TEXT("Initializing AI Controller"))
    Super::BeginPlay();
    if (BehaviorTree)
    {
        RunBehaviorTree(BehaviorTree);

        // Initialize visibility as false or some default state
        bool bIsPlayerVisible = false; // Default to false or use a function to determine visibility

        // Update the Blackboard with initial visibility
        GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerVisible"), bIsPlayerVisible);

        bIsVisible = BlackboardComp->GetValueAsBool(FName("IsPlayerVisible"));
    }
}