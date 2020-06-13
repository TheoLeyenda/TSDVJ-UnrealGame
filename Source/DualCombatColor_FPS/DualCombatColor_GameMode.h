// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DualCombatColor_GameMode.generated.h"

/**
 * 
 */
class APawnObjectDestructibleTarget;

UCLASS()
class DUALCOMBATCOLOR_FPS_API ADualCombatColor_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ADualCombatColor_GameMode();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<APawnObjectDestructibleTarget> cuboRojo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<APawnObjectDestructibleTarget> cuboAzul;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
		//TArray<TSubclassOf<APawn>> ObjectsToSpawn;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
		//TSubclassOf<APawn> ObjectsToSpawn_pito;
		//Forward Declaration

	//UPROPERTY()
		//TArray<class AActor*> instantiatedObjects;

	//UPROPERTY()
		//class AActor *Actor;

	//UPROPERTY()
		//class AActor *Actor2;
	//UPROPERTY(EditAnywhere)
	float coord_Z = 500.0f;

	UPROPERTY(EditAnywhere)
		float countObjectsForRound;

	UPROPERTY(EditAnywhere)
		float minRotation_X;

	UPROPERTY(EditAnywhere)
		float maxRotation_X;

	UPROPERTY(EditAnywhere)
		float minRotation_Y;

	UPROPERTY(EditAnywhere)
		float maxRotation_Y;

	UPROPERTY(EditAnywhere)
		float minRotation_Z;

	UPROPERTY(EditAnywhere)
		float maxRotation_Z;

	UPROPERTY(EditAnywhere)
		float maxCoord_X;

	UPROPERTY(EditAnywhere)
		float minCoord_X;

	UPROPERTY(EditAnywhere)
		float maxCoord_Y;

	UPROPERTY(EditAnywhere)
		float minCoord_Y;

	UPROPERTY(EditAnywhere)
		float startDelayRound;

	UPROPERTY(EditAnywhere)
		float timeRound;
	
	//template<APawn*>
	//void SpawnObject(TSubclassOf<APawn> object, FVector &position, FRotator &rotation);

	void SpawnObject();

	FVector GetRandomPosition();

	FRotator GetRandomRotator();

	void StartGame();

	void ResultRound();

	void ResetPositionPlayer();

	void StartNextRound();

	//void DestroyObjects();

};


