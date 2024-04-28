// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameplayTagContainer.h"
#include "RadarComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRadarStateChangedDelegate);

UENUM(BlueprintType)
enum class ERadarState : uint8
{
	Standard UMETA(DisplayName = "Standard"),
	Enhanced UMETA(DisplayName = "Enhanced")
};

USTRUCT(BlueprintType)
struct FTrackedActorStruct
{
	GENERATED_BODY()
public:
	AActor* Actor;
	FGameplayTag Tag;
	int32 Quadrant;
};





UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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
    // Radar detection capsule
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Radar")
    UCapsuleComponent* RadarCapsule;

    // Detection radius
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
    float DetectionRadius;

    // Type of actor to detect
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
    TSubclassOf<AActor> ActorToDetectClass;

    // Array of tracked actors
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Radar")
    TArray<FTrackedActorStruct> TrackedActors;

    // Functions to handle overlap events
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    // Function to update actor movement status
    void UpdateActorMovementStatus(AActor* Actor, bool IsMoving);

    // Blueprint functions to manipulate and access radar data
    UFUNCTION(BlueprintCallable, Category = "Radar")
    void AddTrackedActor(AActor* Actor, FGameplayTag Tag, int32 Quadrant);

    UFUNCTION(BlueprintCallable, Category = "Radar")
    void RemoveTrackedActor(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "Radar")
    TArray<FTrackedActorStruct> GetTrackedActors() const;
};
