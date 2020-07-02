// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DefeatMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API UDefeatMenuWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* textYouScore;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonRetry;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonExit;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UWidget* CanvasDefeatMenu;
public:
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;

	void ActivateMe();

	void SetScoreText(int _score);

	UFUNCTION()
		void OnClickButtonRetry();

	UFUNCTION()
		void OnClikedButtonExit();

	UFUNCTION()
		void ExitGame();
};
