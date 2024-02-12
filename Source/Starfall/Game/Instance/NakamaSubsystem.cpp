// Fill out your copyright notice in the Description page of Project Settings.


#include "NakamaSubsystem.h"
#include <NakamaClient.h>
#include <NakamaRealtimeClient.h>

void UNakamaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	
	UE_LOG(LogTemp, Display, TEXT("NAKAMA SUBSYSTEM GO VROOM"));


	//	Default Client Parameters
	FString ServerKey = TEXT("defaultkey");
	FString Host = TEXT("127.0.0.1");
	int32 Port = 7350;
	bool bUseSSL = false;
	bool bEnableDebug = true;

	NakamaClient = UNakamaClient::CreateDefaultClient(ServerKey, Host, Port, bUseSSL, bEnableDebug);
}



void UNakamaSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Display, TEXT("De-initializing NAKAMA SUBSYSTEM"));
}




void UNakamaSubsystem::AuthenticatePlayer()
{
	//	Authentication Parameters
	FString Email = TEXT("debug@mail.com");
	FString Password = TEXT("verysecretpassword");
	FString Username = TEXT("exo");
	TMap<FString, FString> Variables;


	//	authenticate player w/ platform
	//	get token


	PlatformAuthToken = "test";

	if (!PlatformAuthToken.IsEmpty())
	{

		
		NakamaClient->AuthenticateEmail(
			Email, 
			Password, 
			Username, 
			true, 
			Variables, 
			AuthenticationSuccessDelegate, 
			AuthenticationErrorDelegate
		);
		
		//	AuthenticationSuccessDelegate.AddDynamic(this, &UNakamaSubsystem::OnAuthenticationSuccess);
		//	AuthenticationErrorDelegate.AddDynamic(this, &UNakamaSubsystem::OnAuthenticationError);

	}
	else {
		//	Get Platform Auth Token
		UE_LOG(LogTemp, Display, TEXT("Platform auth token is empty"));
	}
}



void UNakamaSubsystem::ConnectToRealtimeClient(UNakamaSession* Session)
{
	UE_LOG(LogTemp, Display, TEXT("Player is authenticated"));

	//	Update our session to the passed thru input
	NakamaSession = Session;


	NakamaRtClient = NakamaClient->SetupRealtimeClient();

	bool bCreateStatus = true;
	NakamaRtClient->Connect(NakamaSession, bCreateStatus, RealtimeClientConnectionSuccessDelegate, RealtimeClientConnectionErrorDelegate);
}