// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorObstacleRay.generated.h"

class UStaticMesh;
class UMaterialInterface;
class UStaticMeshComponent;

UCLASS()
class DUALCOMBATCOLOR_FPS_API AActorObstacleRay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorObstacleRay();

	UPROPERTY(EditAnywhere)
		float Damage;

	UPROPERTY(EditAnywhere)
		float TraceDistance = 5;

	UPROPERTY(EditDefaultsOnly)
		TEnumAsByte<ECollisionChannel> TraceChannel;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void CheckShootRay();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
