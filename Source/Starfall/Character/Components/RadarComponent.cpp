// Fill out your copyright notice in the Description page of Project Settings.


#include "RadarComponent.h"
#include <Starfall/Character/StarfallCharacter.h>

// Sets default values for this component's properties
URadarComponent::URadarComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	RadarCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Radar Capsulse Component"));
	RadarCapsule->InitCapsuleSize(Radius, Radius);
	RadarCapsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RadarCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
	RadarCapsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RadarCapsule->bAutoActivate = true;
	RadarCapsule->SetVisibleFlag(true);
	RadarCapsule->bHiddenInGame = false;
	RadarCapsule->OnComponentBeginOverlap.AddDynamic(this, &URadarComponent::OnActorDetected);
	//	RadarCapsule->OnComponentEndOverlap.AddDynamic(this, &URadarComponent::OnActorEndDetected);
}


// Called when the game starts
void URadarComponent::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner())
	{
		RadarCapsule->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	}
}


// Called every frame
void URadarComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URadarComponent::OnActorDetected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == GetOwner()) return;

	AStarfallCharacter* DetectedActor = Cast<AStarfallCharacter>(OtherActor);

	if (DetectedActor)
	{
		//	List tags
		
		//	For every tag in tag container:
		//	print FNAME
		//	for (const FGameplayTag& Tag : DetectedActor->ActorTags)
		//	{
		//		FString TagName = Tag.ToString();
		//		UE_LOG(LogTemp, Warning, TEXT("GameplayTag: %s"), *TagName)
		//	}



		if (DetectedActor->ActorTags.HasTag(EnemyTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy Detected"))
			// Initialize Actor Tracker
		}
		else if (DetectedActor->ActorTags.HasTag(AllyTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("Ally Detected"))
			// Initialize Actor Tracker
		}
		//	else if (DetectedActor->ActorTags.HasTag(ObjectiveTag))
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("Objective Detected"))
		//	}
		else {
			UE_LOG(LogTemp, Display, TEXT("Actor does not have tag %s"), *EnemyTag.ToString());
		}
	}
	else 
	{
		UE_LOG(LogTemp, Display, TEXT("Actor is not Starfall Character"))
	}
}



void URadarComponent::OnActorEndDetected()
{
	//	Actor has been detected
	//	Fire off event
	//	Track actor
	//	so on so on
}