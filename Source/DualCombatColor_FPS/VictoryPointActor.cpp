// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryPointActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "AssetLoaderManager.h"

// Sets default values
AVictoryPointActor::AVictoryPointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVictoryPointActor::BeginPlay()
{
	Super::BeginPlay();
	if (bForceInitialPosition) 
	{
		SetActorLocation(InitialPosition);
		SetActorRotation(InitialRotation);
	}

	AAssetLoaderManager* AssetLoader = Cast<AAssetLoaderManager>(AAssetLoaderManager::StaticClass()->GetDefaultObject());
	AssetLoader->AddAssetToLoad(MeshTP);
	AssetLoader->OnAssetsLoadedDelegate.AddUObject(this, &AVictoryPointActor::OnAssetLoadingComplete);
}

void AVictoryPointActor::OnAssetLoadingComplete()
{
	MeshTP->SetSkeletalMesh(MeshTP_Ptr.Get());
}

// Called every frame
void AVictoryPointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

