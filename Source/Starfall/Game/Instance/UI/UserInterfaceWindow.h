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





//  --------------------------------------------------------------------
//  
//  --------------------------------------------------------------------
//  USTRUCT(BlueprintType)
//  struct FUIWidgetLayer
//  {
//      GENERATED_BODY()
//  
//  public:
//      UPROPERTY(BlueprintReadWrite, Category = "UI Window")
//      UCommonActivatableWidgetStack* Layer;
//  
//  
//      UPROPERTY(BlueprintReadWrite, Category = "UI Window")
//      FGameplayTag Tag;
//  };




//  --------------------------------------------------------------------
//  
//  --------------------------------------------------------------------
UCLASS(Blueprintable)
class STARFALL_API UUserInterfaceWindow : public UCommonUserWidget
{
	GENERATED_BODY()
	

public:
	UUserInterfaceWindow(const FObjectInitializer& ObjectInitializer);

    //  EVENTS ---------------------------------------------------------


    //  FOnRegisteredLayerDelegate* OnRegisteredLayer;



    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
    FGameplayTagContainer UITagContainer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
    TMap<FGameplayTag, UCommonActivatableWidgetStack*> UILayers;
    //  TArray<FUIWidgetLayer> UILayers;




    UPROPERTY(BlueprintReadOnly, Category = "Layers", meta = (AllowPrivateAccess = "true"))
    UCommonActivatableWidgetStack* MenuLayer;

    UPROPERTY(BlueprintReadOnly, Category = "Layers", meta = (AllowPrivateAccess = "true"))
    UCommonActivatableWidgetStack* GameMenuLayer;

    UPROPERTY(BlueprintReadOnly, Category = "Layers", meta = (AllowPrivateAccess = "true"))
    UCommonActivatableWidgetStack* GameLayer;

    UPROPERTY(BlueprintReadOnly, Category = "Layers", meta = (AllowPrivateAccess = "true"))
    UCommonActivatableWidgetStack* ModalLayer;

    UPROPERTY(BlueprintReadOnly, Category = "Layers", meta = (AllowPrivateAccess = "true"))
    UWidget* LocalWidgetTree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UOverlay* MainOverlay;


    int32 Depth = 0;


    UFUNCTION(BlueprintCallable, Category = "UI Log")
    void LogWidgetHierarchy(UWidget* Widget, int32 Depth);

    /*



    UFUNCTION(BlueprintCallable, Category = "UI")
    UOverlaySlot* AddUILayer(UClass* WidgetClass, const FName& LayerTag);
    UFUNCTION(BlueprintCallable, Category = "UI")
    UCommonActivatableWidgetStack* GetUILayerByTag(FGameplayTag Tag);
    void ForEachTag();
    */

    virtual void NativeConstruct() override;
    UOverlaySlot* AddUILayer(TSubclassOf<UCommonActivatableWidgetStack> WidgetClass, const FName& LayerTag);
    void RegisterUILayer(UCommonActivatableWidgetStack* Layer, FGameplayTag Tag);



    //  UFUNCTION(BlueprintCallable, Category = "UI")
    UCommonActivatableWidgetStack* GetUIWindowLayer(FGameplayTag Tag);
   

    //  UFUNCTION(BlueprintCallable, Category = "UI")
    //  void PushWidgetToLayer(TEnumAsByte<EUILayer> Layer, UUserWidget* Widget);





    UFUNCTION(BlueprintCallable, Category = "UI")
    void PushToLayer(FGameplayTag Tag, TSubclassOf<UUserWidget> Widget);
};



