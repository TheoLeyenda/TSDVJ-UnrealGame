// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DualCombatColor_FPSHUD.generated.h"

UCLASS()
class ADualCombatColor_FPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	ADualCombatColor_FPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

