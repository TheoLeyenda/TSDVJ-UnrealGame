// Fill out your copyright notice in the Description page of Project Settings.


#include "DefeatMenuWidget.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "kismet/GameplayStatics.h"
#include "Components/Widget.h"

void UDefeatMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CanvasDefeatMenu->SetVisibility(ESlateVisibility::Hidden);

	if (ButtonRetry != nullptr)
	{
		ButtonRetry->OnClicked.AddDynamic(this, &ThisClass::OnClickButtonRetry);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
	if (ButtonExit != nullptr)
	{
		ButtonExit->OnClicked.AddDynamic(this, &ThisClass::OnClikedButtonExit);
		//UE_LOG(LogTemp, Warning, TEXT("Boton seteado"));
	}
}

void UDefeatMenuWidget::ActivateMe()
{
	if (CanvasDefeatMenu != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("ActivateMe VictoryMenuWidget"));
		CanvasDefeatMenu->SetVisibility(ESlateVisibility::Visible);
	}
}

void UDefeatMenuWidget::SetScoreText(int _score)
{
	if (textYouScore != nullptr)
	{
		FString text = FString::Printf(TEXT("%s, %i"), *textYouScore->Text.ToString(), _score);
		
		//FString text1 = textYouScore->Text.ToString();
		//FString text2 = FString::Printf(TEXT("%i"), _score);

		//FString text = text1 + text2;
		//Hace que el texto escrito "Score:" le agrege el puntaje a mostrar (" " +_score) tal que quede por ejemplo: "Score: 0"
		textYouScore->SetText(FText::FromString(text));
	}
}

void UDefeatMenuWidget::OnClickButtonRetry()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UDefeatMenuWidget::OnClikedButtonExit()
{
	ExitGame();
}

void UDefeatMenuWidget::ExitGame()
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


void UDefeatMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();
	if (ButtonRetry != nullptr)
	{
		if (ButtonRetry->OnClicked.IsAlreadyBound(this, &ThisClass::OnClickButtonRetry))
		{
			ButtonRetry->OnClicked.RemoveDynamic(this, &ThisClass::OnClickButtonRetry);
		}
	}
	if (ButtonExit != nullptr)
	{
		if (ButtonExit->OnClicked.IsAlreadyBound(this, &ThisClass::OnClikedButtonExit))
		{
			ButtonExit->OnClicked.RemoveDynamic(this, &ThisClass::OnClikedButtonExit);
		}
	}
}
