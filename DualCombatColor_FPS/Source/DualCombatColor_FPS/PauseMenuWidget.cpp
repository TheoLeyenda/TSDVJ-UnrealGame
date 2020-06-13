// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuWidget.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "kismet/GameplayStatics.h"
#include "Components/Widget.h"

void UPauseMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (ButtonResume != nullptr)
	{
		ButtonResume->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonResume);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
	if (BackToMenu != nullptr)
	{
		BackToMenu->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonBackToMenu);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
	if (ButtonExit != nullptr)
	{
		ButtonExit->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonExit);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
}

void UPauseMenuWidget::ActivateMe()
{
	if (CanvasPauseMenu != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("ActivateMe"));
		CanvasPauseMenu->SetVisibility(ESlateVisibility::Visible);
	}
}

void UPauseMenuWidget::DeactivateMe()
{
	if (CanvasPauseMenu != nullptr)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		//UE_LOG(LogTemp, Warning, TEXT("DeactivateMe"));
		CanvasPauseMenu->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UPauseMenuWidget::OnClikedButtonResume()
{
	DeactivateMe();
}

void UPauseMenuWidget::OnClikedButtonBackToMenu()
{
	if (Map == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Mapa Nulo"));
	}
	if (Map != nullptr)
	{
		FName nameMap = FName(*Map.GetAssetName());
		UGameplayStatics::OpenLevel(this, nameMap);
		//UE_LOG(LogTemp, Warning, TEXT("Cargando Mapa"));
	}
}

void UPauseMenuWidget::OnClikedButtonExit()
{
	ExitGame();
}

void UPauseMenuWidget::ExitGame()
{
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController != nullptr)
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), playerController, EQuitPreference::Quit, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Encontro al player controller (ExitGame)"));
	}
}

void UPauseMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();
	if (ButtonResume != nullptr)
	{
		if (ButtonResume->OnClicked.IsAlreadyBound(this, &ThisClass::OnClikedButtonResume))
		{
			ButtonResume->OnClicked.RemoveDynamic(this, &ThisClass::OnClikedButtonResume);
			//UE_LOG(LogTemp, Warning, TEXT("Boton Eliminado"));
		}
	}
	if (BackToMenu != nullptr)
	{
		if (BackToMenu->OnClicked.IsAlreadyBound(this, &ThisClass::OnClikedButtonBackToMenu))
		{
			BackToMenu->OnClicked.RemoveDynamic(this, &ThisClass::OnClikedButtonBackToMenu);
			//UE_LOG(LogTemp, Warning, TEXT("Boton Eliminado"));
		}
	}
	if (ButtonExit != nullptr)
	{
		if (ButtonExit->OnClicked.IsAlreadyBound(this, &ThisClass::OnClikedButtonExit))
		{
			ButtonExit->OnClicked.RemoveDynamic(this, &ThisClass::OnClikedButtonExit);
			//UE_LOG(LogTemp, Warning, TEXT("Boton Eliminado"));
		}
	}
}
