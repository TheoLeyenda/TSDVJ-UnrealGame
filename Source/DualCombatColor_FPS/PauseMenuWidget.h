// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonResume;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonExit;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* BackToMenu;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UWidget* CanvasPauseMenu;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UWorld> Map;
public:
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
	
	void ActivateMe();

	void DeactivateMe();

	UFUNCTION()
		void OnClikedButtonResume();

	UFUNCTION()
		void OnClikedButtonBackToMenu();
	UFUNCTION()
		void OnClikedButtonExit();

	UFUNCTION()
		void ExitGame();
};
