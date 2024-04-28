// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UserInterfaceWindow.h"
#include "Blueprint/UserWidget.h"
#include "UserInterfaceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUISuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUIError);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReadyForWidgets);

UCLASS()
class STARFALL_API UUserInterfaceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()




protected:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
    UPROPERTY(BlueprintAssignable, Category = "UI Event")
    FOnUISuccess OnUISuccess;

    UPROPERTY(BlueprintAssignable, Category = "UI Event")
    FOnUIError OnUIError;

    UPROPERTY(BlueprintAssignable, Category = "UI Event")
    FOnReadyForWidgets OnReadyForWidgets;

    UFUNCTION(BlueprintCallable, Category = "UI Window")
    UCommonActivatableWidgetStack* GetUILayer(FGameplayTag Tag);

    //  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    //  TSubclassOf<UUserWidget> UIWindowClass;


    //  UPROPERTY(Transient)
    //  UUserInterfaceWindow* UIWindow = nullptr;





    //  Function to create and display the UI
    UUserInterfaceWindow* Mount();
    UUserInterfaceWindow* UIWindow;

    UFUNCTION(BlueprintCallable, Category = "UI Subsystem")
    UUserInterfaceWindow* GetUIWindow() const { return UIWindow; };
};