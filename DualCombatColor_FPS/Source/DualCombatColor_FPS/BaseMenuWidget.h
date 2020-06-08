// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"

/**
 * 
 */

UCLASS()
class DUALCOMBATCOLOR_FPS_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION()
		virtual void Play();
	UFUNCTION()
		virtual void Credits();
	UFUNCTION()
		virtual void Resume();
	UFUNCTION()
		virtual void Retry();
	UFUNCTION()
		virtual void Exit();
	UFUNCTION()
		virtual void BackToMenu();

	UPROPERTY(meta = (BindWidget))
		class UVerticalBox* VBoxButtons;
protected:
private:
	
};
