// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

void AMenuHUD::BeginPlay()
{
	APlayerController* playerController = Cast<APlayerController>(GetOwner());
	if(MenuWidgetClass == nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("EL Widget ES NULISIMO"));
	}
	if (playerController != nullptr && MenuWidgetClass != nullptr)
	{
		MenuWidget = CreateWidget<UMainMenuWidget>(playerController, MenuWidgetClass, FName("MainMenuWidget"));
		MenuWidget->AddToViewport();
		//UE_LOG(LogTemp, Warning, TEXT("CREE EL MENU WIDGET PAPA"));
	}
}
