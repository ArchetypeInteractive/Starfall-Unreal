// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "GameplayTagContainer.h"

#include "Components/Overlay.h"
#include "Components/StackBox.h"
#include "Components/TextBlock.h"

#include "UserInterfaceWindow.generated.h"






USTRUCT(BlueprintType)
struct FUIWidgetLayer
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = "UI Window")
    UCommonActivatableWidgetStack* Layer;

    UPROPERTY(BlueprintReadWrite, Category = "UI Window")
    FGameplayTag Tag;
};







UCLASS()
class STARFALL_API UUserInterfaceWindow : public UCommonUserWidget
{
	GENERATED_BODY()
	

public:
	UUserInterfaceWindow(const FObjectInitializer& ObjectInitializer);



    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Layers")
    FGameplayTagContainer UITagContainer;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Window")
    TArray<FUIWidgetLayer> UILayers;





    UPROPERTY(BlueprintReadOnly, Category = "UI Layers")
    UCommonActivatableWidgetStack* MenuLayer;

    UPROPERTY(BlueprintReadOnly, Category = "UI Layers")
    UCommonActivatableWidgetStack* GameMenuLayer;

    UPROPERTY(BlueprintReadOnly, Category = "UI Layers")
    UCommonActivatableWidgetStack* GameLayer;

    UPROPERTY(BlueprintReadOnly, Category = "UI Layers")
    UCommonActivatableWidgetStack* ModalLayer;

    UPROPERTY(BlueprintReadOnly, Category = "UI Layers")
    UWidget* LocalWidgetTree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UOverlay* MainOverlay;


    int32 Depth = 0;

    void LogWidgetHierarchy(UWidget* Widget, int32 Depth);


    virtual void NativeConstruct() override;

    void RegisterLayer(UCommonActivatableWidgetStack* Layer, FGameplayTag Tag);

    //  UFUNCTION(BlueprintCallable, Category = "UI")
    //  void PushWidgetToLayer(TEnumAsByte<EUILayer> Layer, UUserWidget* Widget);
};
