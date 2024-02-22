// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameplayTagContainer.h"
#include "RadarComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFALL_API URadarComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadarComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Radar", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* RadarCapsule;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float Radius = 400.f;

	UFUNCTION()
	void OnActorDetected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnActorEndDetected();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag EnemyTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag AllyTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag ObjectiveTag;
};
