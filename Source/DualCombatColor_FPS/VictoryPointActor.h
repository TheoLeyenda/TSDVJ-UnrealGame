// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VictoryPointActor.generated.h"

class USkeletalMeshComponent;
class USkeletalMesh;

UCLASS()
class DUALCOMBATCOLOR_FPS_API AVictoryPointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVictoryPointActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USkeletalMeshComponent* MeshTP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSoftObjectPtr<USkeletalMesh> MeshTP_Ptr;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
		void OnAssetLoadingComplete();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
