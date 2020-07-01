// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_PlayerWidget.h"
#include "Components/TextBlock.h"
#include "Components/Widget.h"

void UUI_PlayerWidget::SetScoreText(int _score)
{
	if (textScore != nullptr)
	{
		textScore->SetText(FText::FromString("Score: "));

		FString text = FString::Printf(TEXT("%s %i"), *textScore->Text.ToString(), _score);

		textScore->SetText(FText::FromString(text));
	}
}
void UUI_PlayerWidget::SetCurrentLevelText(int _currentLevel)
{
	if (textCurrentLevel != nullptr)
	{
		textCurrentLevel->SetText(FText::FromString("Level "));

		FString text = FString::Printf(TEXT("%s %i"), *textCurrentLevel->Text.ToString(), _currentLevel);

		textCurrentLevel->SetText(FText::FromString(text));
	}
}
void UUI_PlayerWidget::SetCurrentLifeText(int _currentLife)
{
	if (textCurrentLife != nullptr)
	{
		textCurrentLife->SetText(FText::FromString("Life: "));

		FString text = FString::Printf(TEXT("%s %i"), *textCurrentLife->Text.ToString(), _currentLife);

		textCurrentLife->SetText(FText::FromString(text));
	}
}