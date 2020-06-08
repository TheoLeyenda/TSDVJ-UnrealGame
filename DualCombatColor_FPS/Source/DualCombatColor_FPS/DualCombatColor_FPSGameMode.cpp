// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DualCombatColor_FPSGameMode.h"
#include "DualCombatColor_FPSHUD.h"
#include "DualCombatColor_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADualCombatColor_FPSGameMode::ADualCombatColor_FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADualCombatColor_FPSHUD::StaticClass();
}
