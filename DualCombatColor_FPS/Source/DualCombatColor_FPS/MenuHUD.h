// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuWidget.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TSubclassOf<UMainMenuWidget> MenuWidgetClass;

	UPROPERTY(BlueprintReadOnly)
		UMainMenuWidget* MenuWidget;

	virtual void BeginPlay() override;
};
