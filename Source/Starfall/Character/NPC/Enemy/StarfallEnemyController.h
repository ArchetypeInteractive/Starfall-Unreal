// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "StarfallEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API AStarfallEnemyController : public AAIController
{
	GENERATED_BODY()


public:
	AStarfallEnemyController();
	

	virtual void BeginPlay() override;

	bool bIsVisible;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

private:
	UBlackboardComponent* BlackboardComp;
};
