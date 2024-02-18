// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/UserInterfaceWindow.h"
#include "Blueprint/UserWidget.h"
#include "UserInterfaceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWindowUILoadSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWindowUILoadError);



UCLASS()
class STARFALL_API UUserInterfaceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()





	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;


    void UITestMethod();





public:
    UPROPERTY(BlueprintAssignable, Category="UI Event")
    FOnWindowUILoadSuccess OnWindowUILoadSuccess;

    UPROPERTY(BlueprintAssignable, Category = "UI Event")
    FOnWindowUILoadError OnWindowUILoadError;


    UPROPERTY(Transient)
    UUserInterfaceWindow* UIWindow = nullptr;

    UFUNCTION(BlueprintCallable, Category = "UI Subsystem")
    UUserInterfaceWindow* GetUIWindow() const { return UIWindow; }




    // Function to create and display the UI
    void CreateAndDisplayUI();
};
