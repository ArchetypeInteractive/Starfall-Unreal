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
	//	RadarCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
	RadarCapsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RadarCapsule->bAutoActivate = true;
	RadarCapsule->SetVisibleFlag(true);
	RadarCapsule->bHiddenInGame = false;
	RadarCapsule->OnComponentBeginOverlap.AddDynamic(this, &URadarComponent::OnActorDetected);
	RadarCapsule->OnComponentEndOverlap.AddDynamic(this, &URadarComponent::OnActorEndDetected);
}


// Called when the game starts
void URadarComponent::BeginPlay()
{
	Super::BeginPlay();
	if (AStarfallCharacter* OwnerCharacter = Cast<AStarfallCharacter>(GetOwner()))
	{
		RadarCapsule->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		OwnerCharacter->OnCharacterMoved.AddDynamic(this, &URadarComponent::UpdateTrackedActorLocations);
		OwnerCharacter->OnCharacterLooked.AddDynamic(this, &URadarComponent::UpdateTrackedActorLocations);
		
		UpdateTrackedActorLocations();
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
		//	create array

		if (DetectedActor->ActorTags.HasTag(EnemyTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy Detected"))

			FTrackedActorStruct NewTrackedActor;
			NewTrackedActor.Actor = DetectedActor;
			NewTrackedActor.Tag = EnemyTag;

			TrackedActors.Add(NewTrackedActor);
			DetectedActor->OnCharacterMoved.AddDynamic(this, &URadarComponent::UpdateTrackedActorLocations);
		}
		if (DetectedActor->ActorTags.HasTag(AllyTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("Ally Detected"))
			// Initialize Actor Tracker
		}
	}
	else 
	{
		UE_LOG(LogTemp, Display, TEXT("Actor is not Starfall Character"))
	}
}



void URadarComponent::OnActorEndDetected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AStarfallCharacter* Character = Cast<AStarfallCharacter>(OtherActor);
		if (Character)
		{
			Character->OnCharacterMoved.RemoveDynamic(this, &URadarComponent::UpdateTrackedActorLocations);
		
			UE_LOG(LogTemp, Log, TEXT("Unsubscribed from OnCharacterMovementUpdated for %s"), *Character->GetName());
		}
	
		for (int32 i = TrackedActors.Num() - 1; i >= 0; --i)
		{
			if (TrackedActors[i].Actor == OtherActor)
			{
				TrackedActors.RemoveAt(i);
				UE_LOG(LogTemp, Warning, TEXT("Actor %s removed from radar tracking"), *OtherActor->GetName());
				break;
			}
		}
	}
	
	UE_LOG(LogTemp, Display, TEXT("Does this event end overlap work?"))
}


void URadarComponent::UpdateTrackedActorLocations()
{
	UE_LOG(LogTemp, Display, TEXT("Tracked actor has moved"))


	FVector PlayerForwardVector = GetOwner()->GetActorForwardVector(); // Get current forward vector
	FVector PlayerLocation = GetOwner()->GetActorLocation();



	for (auto& TrackedActor : TrackedActors)
	{
		if (!TrackedActor.Actor) continue;

		FVector ActorLocation = TrackedActor.Actor->GetActorLocation();
		FVector DirectionToActor = ActorLocation - PlayerLocation;
		// Convert DirectionToActor to local space relative to player orientation
		FVector LocalDirectionToActor = FVector::VectorPlaneProject(DirectionToActor, FVector::UpVector).GetSafeNormal();
		float DotProduct = FVector::DotProduct(PlayerForwardVector.GetSafeNormal(), LocalDirectionToActor);
		float CrossProductZ = FVector::CrossProduct(PlayerForwardVector, LocalDirectionToActor).Z;

		// Determine quadrant based on DotProduct and CrossProductZ
		if (DotProduct >= 0) {
			TrackedActor.Quadrant = (CrossProductZ >= 0) ? 1 : 4; // Front-right or Front-left
		}
		else {
			TrackedActor.Quadrant = (CrossProductZ >= 0) ? 2 : 3; // Back-right or Back-left
		}

		UE_LOG(LogTemp, Warning, TEXT("Quadrant: %d"), TrackedActor.Quadrant)
		// Update UI or logic based on new quadrant assignment
	}



}



void URadarComponent::SetRadarState(ERadarState NewState)
{
	RadarState = NewState;

	if (NewState == ERadarState::Standard)
	{
		NumQuadrants = StandardQuadrantNum;
	}
	else if (NewState == ERadarState::Enhanced)
	{
		NumQuadrants = EnhancedQuadrantNum;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Are you sure you're calling this correctly?"))
	}

	OnRadarStateChanged.Broadcast();
}