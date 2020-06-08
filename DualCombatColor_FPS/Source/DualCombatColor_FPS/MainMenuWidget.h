// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMenuWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
class UButton;
UCLASS()
class DUALCOMBATCOLOR_FPS_API UMainMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()
public:
protected:
	UPROPERTY(EditAnywhere)
		UButton* ButtonPlay;
	UPROPERTY(EditAnywhere)
		UButton* ButtonCredits;
	UPROPERTY(EditAnywhere)
		UButton* ButtonExit;

	virtual void NativeOnInitialized() override;
private:
};
