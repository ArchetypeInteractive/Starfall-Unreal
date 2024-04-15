// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StarfallWeapon.generated.h"

UCLASS()
class STARFALL_API AStarfallWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarfallWeapon();


	// Mesh component for the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* WeaponMesh;


	UStaticMeshComponent* GetMesh() const { return WeaponMesh; };


	int32 MagSize;
	int32 CurrentAmmoCount;
	int32 TotalAmmoCarryingCapacity;


	int32 Perks;	// We will establish an array of Perks. Should these be gameplay abilities??



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Aim();
	void Shoot();
};
