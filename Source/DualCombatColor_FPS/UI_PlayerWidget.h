// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API UUI_PlayerWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* textScore;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* textCurrentLevel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* textCurrentLife;
public:
	void SetScoreText(int _score);
	void SetCurrentLevelText(int _currentLevel);
	void SetCurrentLifeText(int _currentLife);
};
