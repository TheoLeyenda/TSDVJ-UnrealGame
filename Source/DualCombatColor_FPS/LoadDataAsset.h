// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LoadDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSkinVisualData 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		TArray<TSoftObjectPtr<class UMaterial>> MaterialsPtr;

	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<class USkeletalMesh> SkeletalMeshPtr;
};
UCLASS()
class DUALCOMBATCOLOR_FPS_API ULoadDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
		FString Name;

	UPROPERTY(EditDefaultsOnly)
		FSkinVisualData VisualData;

	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<ULoadDataAsset> LoadDataAssetPtr;

};
