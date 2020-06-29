// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ParkourGameInstance.generated.h"

class AAssetLoaderManager;
/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API UParkourGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	void SetAssetLoaderInstance(AAssetLoaderManager* NewManager);
	AAssetLoaderManager* GetAssetLoaderManagerInstance();
private:
	UPROPERTY()
		AAssetLoaderManager* AssetLoaderManager = nullptr;
};
