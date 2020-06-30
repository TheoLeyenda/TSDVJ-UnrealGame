// Fill out your copyright notice in the Description page of Project Settings.

#include "ParkourGameInstance.h"
#include "AssetLoaderManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

// Sets default values
AAssetLoaderManager::AAssetLoaderManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAssetLoaderManager::BeginPlay()
{
	Super::BeginPlay();
	UParkourGameInstance* parkourGameInstance = Cast<UParkourGameInstance>(GetGameInstance());
	parkourGameInstance->SetAssetLoaderInstance(this);
	
}
void AAssetLoaderManager::OnAssetLoaded()
{
	OnAssetsLoadedDelegate.Broadcast();
}
void AAssetLoaderManager::AddAssetToLoad(TSoftObjectPtr<UObject> AssetToBeLoaded)
{
	AssetsToLoad.Add(AssetToBeLoaded);
}
void AAssetLoaderManager::LoadAssets(bool bAsyncLoad) 
{
	TArray<FSoftObjectPath> ItemsToStream;

	FStreamableManager& Streamble = UAssetManager::GetStreamableManager();
	for (int32 i = 0; i < AssetsToLoad.Num(); i++)
	{
		ItemsToStream.AddUnique(AssetsToLoad[i].ToStringReference());
	}
	//Carga Asyncronica (Async)
	Streamble.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &AAssetLoaderManager::OnAssetLoaded));
	
	//FALTA AGREGAR CARGA Syncronica (Sync)
}

