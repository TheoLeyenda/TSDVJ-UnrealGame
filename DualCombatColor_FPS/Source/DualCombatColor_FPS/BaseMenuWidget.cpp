// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UBaseMenuWidget::Play()
{
	UGameplayStatics::OpenLevel(this, "FirstPersonExampleMap");
}
void UBaseMenuWidget::Credits(){}
void UBaseMenuWidget::Resume(){}
void UBaseMenuWidget::Retry(){}
void UBaseMenuWidget::Exit()
{
	//UKismetSystemLibrary::QuitGame(,)
}
void UBaseMenuWidget::BackToMenu(){}
