// Fill out your copyright notice in the Description page of Project Settings.


#include "StarfallWeapon.h"

// Sets default values
AStarfallWeapon::AStarfallWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    // Initialize a Scene Component and set it as the root component
    USceneComponent* RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    SetRootComponent(RootSceneComponent);

    // Initialize the mesh component and attach it to the RootSceneComponent
    WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
    WeaponMesh->SetupAttachment(RootSceneComponent);
    WeaponMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 180.0f));

}

// Called when the game starts or when spawned
void AStarfallWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarfallWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AStarfallWeapon::Aim()
{
    UE_LOG(LogTemp, Display, TEXT(""));

    //  we should pass our player's camera manager here
    //  then we can lerp to/from
}



void AStarfallWeapon::Shoot()
{   
    //  if (input is held) {
        //  then do a thing
    //  }
    UE_LOG(LogTemp, Display, TEXT("Shooting weapon"));
}