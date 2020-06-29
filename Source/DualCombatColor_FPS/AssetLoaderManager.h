// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoaderManager.generated.h"
DECLARE_MULTICAST_DELEGATE(FOnAssetsLoaded);

UCLASS()
class DUALCOMBATCOLOR_FPS_API AAssetLoaderManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAssetLoaderManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		TArray<TSoftObjectPtr<UObject>> AssetsToLoad;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void OnAssetLoaded();

	void AddAssetToLoad(TSoftObjectPtr<UObject> AssetToBeLoaded);

	void LoadAssets(bool bAsyncLoad = true);
	
	FOnAssetsLoaded OnAssetsLoadedDelegate;
};
