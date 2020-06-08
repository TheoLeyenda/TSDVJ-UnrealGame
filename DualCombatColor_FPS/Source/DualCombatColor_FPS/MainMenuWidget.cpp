// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Blueprint/WidgetTree.h"

void UMainMenuWidget::NativeOnInitialized()
{
	//UButton *button = 
	/*UButton* ButtonPlay_local = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	ButtonPlay->OnClicked.AddDynamic(this, &ThisClass::Play);

	UButton* ButtonCredits_local = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	ButtonCredits->OnClicked.AddDynamic(this, &ThisClass::Credits);

	UButton* ButtonExit_local = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	ButtonExit->OnClicked.AddDynamic(this, &ThisClass::Exit);

	VBoxButtons->AddChild(ButtonPlay);
	VBoxButtons->AddChild(ButtonCredits);
	VBoxButtons->AddChild(ButtonExit);*/

	ButtonPlay->OnClicked.AddUniqueDynamic(this, &ThisClass::Play);
	ButtonCredits->OnClicked.AddUniqueDynamic(this, &ThisClass::Credits);
	ButtonExit->OnClicked.AddUniqueDynamic(this, &ThisClass::Exit);
}
