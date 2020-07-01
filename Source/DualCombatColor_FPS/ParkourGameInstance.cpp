// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkourGameInstance.h"
#include "AssetLoaderManager.h"

UParkourGameInstance::UParkourGameInstance()
{
	currentData.currentScore = 0;
	currentData.currentLevel = 1;
}

void UParkourGameInstance::SetAssetLoaderInstance(AAssetLoaderManager* NewManager)
{
	AssetLoaderManager = NewManager;
}

AAssetLoaderManager* UParkourGameInstance::GetAssetLoaderManagerInstance()
{
	return AssetLoaderManager;
}
