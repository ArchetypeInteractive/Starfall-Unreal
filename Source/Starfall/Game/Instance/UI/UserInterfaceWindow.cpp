// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceWindow.h"
#include "Components/OverlaySlot.h"
#include <Components/SizeBox.h>


UUserInterfaceWindow::UUserInterfaceWindow(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Error, TEXT("SETTING UP OUR UI WINDOW!! OMGG"))


    //  Can we run Add UI Layers here as part of this component's set up?
}


void UUserInterfaceWindow::NativeConstruct()
{
    Super::NativeConstruct();


    // Initialize MainOverlay
    MainOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
    if (!MainOverlay) {
        UE_LOG(LogTemp, Error, TEXT("Failed to create MainOverlay"));
        return;
    }
    WidgetTree->RootWidget = MainOverlay;
    MainOverlay->SetVisibility(ESlateVisibility::Visible);  // Make sure it's visible




    // Create and configure a TextBlock for testing visibility
    UTextBlock* TestTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName("TestTextBlock"));
    if (TestTextBlock)
    {
        TestTextBlock->SetText(FText::FromString("Test Visible"));
        TestTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
        TestTextBlock->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 24));

        UOverlaySlot* TextSlot = MainOverlay->AddChildToOverlay(TestTextBlock);
        if (TextSlot)
        {
            TextSlot->SetHorizontalAlignment(HAlign_Center);
            TextSlot->SetVerticalAlignment(VAlign_Center);
        }
    }




    // Attempt to add UI layers
    AddUILayer(UCommonActivatableWidgetStack::StaticClass(), FName("UI.Layer.Menu"));

    UE_LOG(LogTemp, Warning, TEXT("UI layers added and registered"));
}




void UUserInterfaceWindow::LogWidgetHierarchy(UWidget* Widget, int32 LocalDepth)
{
	if (!Widget) return;


	Depth = LocalDepth;

	// Create indentation based on the depth in the hierarchy
	FString Indent = FString::ChrN(Depth * 2, TEXT('-'));

	// Log the widget's class and name
	UE_LOG(LogTemp, Log, TEXT("UI structure: %s %s (%s)"), *Indent, *Widget->GetName(), *Widget->GetClass()->GetName());

	// If the widget is a container, iterate through its children
	if (UPanelWidget* Panel = Cast<UPanelWidget>(Widget))
	{
		for (int32 i = 0; i < Panel->GetChildrenCount(); ++i)
		{
			LogWidgetHierarchy(Panel->GetChildAt(i), Depth + 1);
		}
	}
}



//  ----------------
//  SCOPED UTIL FNs
//  ----------------
UOverlaySlot* UUserInterfaceWindow::AddUILayer(TSubclassOf<UCommonActivatableWidgetStack> WidgetClass, const FName& LayerTag)
{
    if (!WidgetTree || !MainOverlay) {
        UE_LOG(LogTemp, Error, TEXT("WidgetTree or MainOverlay is null."));
        return nullptr;
    }

    // Create and add the ActivatableWidgetStack directly to the MainOverlay
    UCommonActivatableWidgetStack* Layer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(WidgetClass);
    if (!Layer) {
        UE_LOG(LogTemp, Error, TEXT("Failed to construct widget layer."));
        return nullptr;
    }

    UOverlaySlot* LayerSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(Layer));
    if (LayerSlot)
    {
        LayerSlot->SetHorizontalAlignment(HAlign_Fill);
        LayerSlot->SetVerticalAlignment(VAlign_Fill);
    }

    // Ensure layer is visible
    Layer->SetVisibility(ESlateVisibility::Visible);

    // Register the layer with a gameplay tag
    RegisterUILayer(Layer, FGameplayTag::RequestGameplayTag(LayerTag));

    UE_LOG(LogTemp, Log, TEXT("Layer added to MainOverlay successfully with tag: %s"), *LayerTag.ToString());
    return LayerSlot; // Return the Overlay slot containing the Layer
}










void UUserInterfaceWindow::RegisterUILayer(UCommonActivatableWidgetStack* Layer, FGameplayTag Tag)
{

    UE_LOG(LogTemp, Warning, TEXT("Registering layer with tag: %s"), *Tag.ToString());
    if (!Layer) return;		//	If layer is invalid, exit early


    if (!UILayers.Find(Tag))
    {
        UILayers.Add(Tag, Layer);
        if (!UITagContainer.HasTag(Tag)) { UITagContainer.AddTag(Tag); }
    }

}






UCommonActivatableWidgetStack* UUserInterfaceWindow::GetUIWindowLayer(FGameplayTag Tag)
{
    UCommonActivatableWidgetStack** Layer = UILayers.Find(Tag);  // Find the layer by tag

    //  return Layer
    return nullptr;
}





void UUserInterfaceWindow::PushToLayer(FGameplayTag Tag, TSubclassOf<UUserWidget> WidgetClass)
{
    UCommonActivatableWidgetStack** LayerPtr = UILayers.Find(Tag);
    if (LayerPtr)
    {
        UCommonActivatableWidgetStack* Layer = *LayerPtr;
        if (Layer)
        {
            UE_LOG(LogTemp, Warning, TEXT("Pushing widget to layer!"))
            //  Layer->PushWidget(Widget);
        }
    }
}