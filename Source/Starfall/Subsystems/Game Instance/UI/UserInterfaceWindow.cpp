// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceWindow.h"
#include "../../../Character/StarfallHeroController.h"
#include "Components/OverlaySlot.h"





UUserInterfaceWindow::UUserInterfaceWindow(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Display, TEXT("User Interface Window class"))


}


void UUserInterfaceWindow::RegisterLayer(UCommonActivatableWidgetStack* Layer, FGameplayTag Tag)
{

	UE_LOG(LogTemp, Warning, TEXT("Registering layer with tag: %s"), *Tag.ToString());
	if (!Layer)
	{
		UE_LOG(LogTemp, Warning, TEXT("Layer is null!"));
		return;
	}



	if (!UITagContainer.HasTag(Tag))
	{

		FUIWidgetLayer NewRegistration;
		NewRegistration.Layer = Layer;
		NewRegistration.Tag = Tag;
		UILayers.Add(NewRegistration);


		UITagContainer.AddTag(Tag);
	}
}





void UUserInterfaceWindow::NativeConstruct()
{
	Super::NativeConstruct();




	// Use RootWidget as needed





	/*
	//	Create and set MainOverlay as the RootWidget
	MainOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
	MainOverlay->SetVisibility(ESlateVisibility::Visible);
	MainOverlay->bIsEnabled = true;
	WidgetTree->RootWidget = MainOverlay;


	//	Create MenuLayer and add it to MainOverlay
	MenuLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	MenuLayer->SetVisibility(ESlateVisibility::Visible);
	UOverlaySlot* MenuSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(MenuLayer));
	MenuSlot->SetHorizontalAlignment(HAlign_Fill);
	MenuSlot->SetVerticalAlignment(VAlign_Fill);
	RegisterLayer(MenuLayer, FGameplayTag::RequestGameplayTag(FName("UI.Layer.Menu")));


	GameMenuLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	UOverlaySlot* GameMenuSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(GameMenuLayer));
	if (GameMenuSlot)
	{
		GameMenuSlot->SetHorizontalAlignment(HAlign_Fill);
		GameMenuSlot->SetVerticalAlignment(VAlign_Fill);
		RegisterLayer(GameMenuLayer, FGameplayTag::RequestGameplayTag(FName("UI.Layer.GameMenu")));
	}


	ModalLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	UOverlaySlot* ModalSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(ModalLayer));
	if (ModalSlot)
	{
		ModalSlot->SetHorizontalAlignment(HAlign_Fill);
		ModalSlot->SetVerticalAlignment(VAlign_Fill);
		RegisterLayer(ModalLayer, FGameplayTag::RequestGameplayTag(FName("UI.Layer.Modal")));
	}



	GameLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	UOverlaySlot* GameSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(GameLayer));
	if (GameSlot)
	{
		GameSlot->SetHorizontalAlignment(HAlign_Fill);
		GameSlot->SetVerticalAlignment(VAlign_Fill);
		RegisterLayer(GameLayer, FGameplayTag::RequestGameplayTag(FName("UI.Layer.Game")));
	}



	//	MenuLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	//	//	UOverlaySlot* Slot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay(MenuLayer));
	//	UOverlaySlot* MenuSlot = Cast<UOverlaySlot>(MainOverlay->AddChildToOverlay());
	//	MainOverlay->AddChild(MenuLayer);










	//	MenuLayer->SetVisibility(ESlateVisibility::Visible);



	//	GameMenuLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	//	
	//	ModalLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	//	
	//	GameLayer = WidgetTree->ConstructWidget<UCommonActivatableWidgetStack>(UCommonActivatableWidgetStack::StaticClass());
	//	


	//	Create a new StackBox widget
	//	UStackBox* StackBox = WidgetTree->ConstructWidget<UStackBox>(UStackBox::StaticClass());
	//	UTextBlock* TextBlock1 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
	//	TextBlock1->SetText(FText::FromString(TEXT("STARFALL BETA")));
	//	TextBlock1->SetFont(FSlateFontInfo(TEXT("/Engine/EngineFonts/Roboto.Roboto"), 12));
	//	StackBox->AddChild(TextBlock1); // Add to stack box
	//	StackBox->SetVisibility(ESlateVisibility::Visible);




	LogWidgetHierarchy(WidgetTree->RootWidget, Depth);
	*/
	UE_LOG(LogTemp, Display, TEXT("Fucker"));
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
