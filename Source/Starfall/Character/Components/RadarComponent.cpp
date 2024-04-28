// Fill out your copyright notice in the Description page of Project Settings.


#include "RadarComponent.h"
#include <Starfall/Character/StarfallCharacter.h>






// Sets default values for this component's properties
URadarComponent::URadarComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	DetectionRadius = 500.f;
	RadarCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Radar Capsule Component"));
	RadarCapsule->InitCapsuleSize(DetectionRadius, DetectionRadius);
	RadarCapsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//	RadarCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
	RadarCapsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RadarCapsule->bAutoActivate = true;
	RadarCapsule->SetVisibleFlag(true);
	RadarCapsule->bHiddenInGame = false;
	RadarCapsule->OnComponentBeginOverlap.AddDynamic(this, &URadarComponent::OnOverlapBegin);
	RadarCapsule->OnComponentEndOverlap.AddDynamic(this, &URadarComponent::OnOverlapEnd);
}





// Called when the game starts
void URadarComponent::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner())
	{
		RadarCapsule->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		//	OwnerCharacter->OnCharacterMoved.AddDynamic(this, &URadarComponent::OnDetectedActorMoved);
		//	OwnerCharacter->OnCharacterLooked.AddDynamic(this, &URadarComponent::OnDetectedActorMoved);
		//	OnDetectedActorMoved();
	}
}

void URadarComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if the actor is of the class we want to track
    if (OtherActor != nullptr && OtherActor->IsA(ActorToDetectClass))
    {
		UE_LOG(LogTemp, Warning, TEXT("Actor detected"))
        // Add actor to tracked list with default tags and quadrant
        AddTrackedActor(OtherActor, FGameplayTag(), 0);
    }
}

void URadarComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    // Remove actor from tracked list
	UE_LOG(LogTemp, Warning, TEXT("Actor no longer detected"))
    RemoveTrackedActor(OtherActor);
}

void URadarComponent::AddTrackedActor(AActor* Actor, FGameplayTag Tag, int32 Quadrant)
{
    // Add a new tracked actor struct to the array
    FTrackedActorStruct NewTrackedActor;
    NewTrackedActor.Actor = Actor;
    NewTrackedActor.Tag = Tag;
    NewTrackedActor.Quadrant = Quadrant;
    TrackedActors.Add(NewTrackedActor);
}

void URadarComponent::RemoveTrackedActor(AActor* Actor)
{
    // Remove the actor from the tracked array
    TrackedActors.RemoveAll([Actor](const FTrackedActorStruct& Item)
    {
        return Item.Actor == Actor;
    });
}

TArray<FTrackedActorStruct> URadarComponent::GetTrackedActors() const
{
    return TrackedActors;
}