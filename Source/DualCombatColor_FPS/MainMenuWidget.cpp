// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "kismet/GameplayStatics.h"
#include "Components/Widget.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ButtonPlay != nullptr) 
	{
		ButtonPlay->OnClicked.AddDynamic(this, &ThisClass::OnClickedButtonPlay);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
	if(ButtonCredits != nullptr)
	{
		ButtonCredits->OnClicked.AddDynamic(this, &ThisClass::OnClickedButtonCredits);
	}
	if(ButtonExit != nullptr)
	{
		ButtonExit->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonExit);
	}
	if(BackToMenu != nullptr)
	{
		BackToMenu->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonBackToMenu);
	}
	ShowMenuElements();
}



void UMainMenuWidget::OnClickedButtonPlay()
{
	if(Map == nullptr)
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
void UMainMenuWidget::OnClickedButtonCredits()
{
	UE_LOG(LogTemp, Warning, TEXT("Creditos"));
	ShowCreditsElements();	
}

void UMainMenuWidget::OnClikedButtonExit()
{
	ExitGame();
}

void UMainMenuWidget::OnClikedButtonBackToMenu()
{
	ShowMenuElements();
}

void UMainMenuWidget::ExitGame()
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

void UMainMenuWidget::ShowMenuElements()
{
	if (CanvasMenu != nullptr && CanvasCredits != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ShowMenuElements"));
		CanvasMenu->SetVisibility(ESlateVisibility::Visible);
		CanvasCredits->SetVisibility(ESlateVisibility::Hidden);
	}
	/*for (UWidget* menuElements : WidgetMenu)
	{
		if (menuElements != nullptr)
		{
			menuElements->Visibility = ESlateVisibility::Visible;
		}
	}

	for (UWidget* creditsElements : WidgetCredits)
	{
		if (creditsElements != nullptr)
		{
			creditsElements->Visibility = ESlateVisibility::Hidden;
		}
	}*/
}

void UMainMenuWidget::ShowCreditsElements()
{
	if (CanvasMenu != nullptr && CanvasCredits != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ShowCreditsElements"));
		CanvasMenu->SetVisibility(ESlateVisibility::Hidden);
		CanvasCredits->SetVisibility(ESlateVisibility::Visible);
	}
	/*for (UWidget* menuElements : WidgetMenu)
	{
		if (menuElements != nullptr)
		{
			menuElements->Visibility = ESlateVisibility::Hidden;
		}
	}

	for (UWidget* creditsElements : WidgetCredits)
	{
		if (creditsElements != nullptr)
		{
			creditsElements->Visibility = ESlateVisibility::Visible;
		}
	}*/
}

void UMainMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();
	if (ButtonPlay != nullptr) 
	{
		if (ButtonPlay->OnClicked.IsAlreadyBound(this, &ThisClass::OnClickedButtonPlay))
		{
			ButtonPlay->OnClicked.RemoveDynamic(this, &ThisClass::OnClickedButtonPlay);
			//UE_LOG(LogTemp, Warning, TEXT("Boton Eliminado"));
		}
	}
	if (ButtonCredits != nullptr)
	{
		if (ButtonCredits->OnClicked.IsAlreadyBound(this, &ThisClass::OnClickedButtonCredits))
		{
			ButtonCredits->OnClicked.RemoveDynamic(this, &ThisClass::OnClickedButtonCredits);
			//UE_LOG(LogTemp, Warning, TEXT("Boton Eliminado"));
		}
	}
	if(ButtonExit != nullptr)
	{
		if (ButtonExit->OnClicked.IsAlreadyBound(this, &ThisClass::OnClikedButtonExit))
		{
			ButtonExit->OnClicked.RemoveDynamic(this, &ThisClass::OnClikedButtonExit);
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
}
