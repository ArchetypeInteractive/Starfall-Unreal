// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NakamaSubsystem.generated.h"






UCLASS()
class STARFALL_API UNakamaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	float Session;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	float Client;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	float RtClient;

	//	UPROPERTY(BlueprintCallable)
	//	void TestFunction() const { return nullptr; };

	//  authenticate with server
	//	store authenticated session here
	//	session = GetSession() or something
	//	connect to client
	//	store client here
	//	connect to realtime client
	//	store client here
};
