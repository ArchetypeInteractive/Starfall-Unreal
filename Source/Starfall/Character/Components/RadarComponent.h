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





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFALL_API URadarComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadarComponent();


	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FOnRadarStateChangedDelegate OnRadarStateChanged;




	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Radar", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* RadarCapsule;

	// Current state of the radar
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
	ERadarState RadarState = ERadarState::Standard;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float Radius = 5000.f;

	UFUNCTION()
	void OnActorDetected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnActorEndDetected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
	void UpdateTrackedActorLocations();


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag EnemyTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag AllyTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags", meta = (AllowPrivateAccess = "true"))
	FGameplayTag ObjectiveTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
	int32 NumQuadrants; 
	int32 StandardQuadrantNum = 8;
	int32 EnhancedQuadrantNum = 16;

	UFUNCTION(BlueprintCallable, Category = "State")
	void SetRadarState(ERadarState NewState);

	TArray<FTrackedActorStruct> TrackedActors;
};
