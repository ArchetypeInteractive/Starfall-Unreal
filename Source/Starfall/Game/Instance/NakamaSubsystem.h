// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//	#include "Engine/GameInstance.h"
#include "Delegates/Delegate.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"
#include "NakamaUnreal.h"
#include "NakamaClient.h"
#include "NakamaSession.h"
#include "NakamaRealtimeClient.h"
#include "NakamaSubsystem.generated.h"









UCLASS()
class STARFALL_API UNakamaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	




public:
	//	UFUNCTION(BlueprintCallable)
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable)
	virtual void Deinitialize() override;


	// Event dispatched when authentication completes
	UPROPERTY(BlueprintAssignable, Category = "Authentication")
	FOnError AuthenticationErrorDelegate;

	UPROPERTY(BlueprintAssignable, Category = "Authentication")
	FOnAuthUpdate AuthenticationSuccessDelegate;


	void OnAuthenticationSuccess(UNakamaSession* Session);
	void OnAuthenticationError(const FNakamaError& Error);






	/*
	UPROPERTY(BlueprintAssignable, Category = "Character")
	FOnRealtimeClientConnected ConnectionSuccessDelegate;

	UPROPERTY(BlueprintAssignable, Category = "Character")
	FOnRealtimeClientConnectionError ConnectionErrorDelegate;

	UFUNCTION(BlueprintCallable)
	void OnRealtimeClientConnectSuccess();

	UFUNCTION(BlueprintCallable)
	void OnRealtimeClientConnectError(const FNakamaRtError& ErrorData);
	*/








	FString PlatformAuthToken;


	UFUNCTION(BlueprintCallable)
	void AuthenticatePlayer();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	UNakamaSession* PlayerSession;
	//	UNakamaSession* GetNakamaSession() const { return Session; };


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	UNakamaClient* NakamaClient;
	//	UNakamaClient* GetNakamaClient() const { return Client; };


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama")
	UNakamaRealtimeClient* PlayerRtClient;
	//	UNakamaRealtimeClient* GetRtClient() const { return RtClient; };








	void OnAuthenticationSuccess();
	void OnAuthenticationError();







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
