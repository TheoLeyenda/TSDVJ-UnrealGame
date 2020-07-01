// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ParkourGameInstance.generated.h"

USTRUCT()
struct FCurrentData
{
	GENERATED_BODY()
public:
	UPROPERTY()
		int currentScore;
	UPROPERTY()
		int currentLevel;
	//UPROPERTY()
		//int currentLifePlayer;
};

class AAssetLoaderManager;
/**
 * 
 */
UCLASS()
class DUALCOMBATCOLOR_FPS_API UParkourGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UParkourGameInstance();

	UPROPERTY()
		FCurrentData currentData;
	
	void SetAssetLoaderInstance(AAssetLoaderManager* NewManager);
	AAssetLoaderManager* GetAssetLoaderManagerInstance();
private:
	UPROPERTY()
		AAssetLoaderManager* AssetLoaderManager = nullptr;
};
