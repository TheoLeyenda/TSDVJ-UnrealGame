// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkourGameInstance.h"
#include "AssetLoaderManager.h"

void UParkourGameInstance::SetAssetLoaderInstance(AAssetLoaderManager* NewManager)
{
	AssetLoaderManager = NewManager;
}

AAssetLoaderManager* UParkourGameInstance::GetAssetLoaderManagerInstance()
{
	return AssetLoaderManager;
}
