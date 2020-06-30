// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorObstacleCanyon.generated.h"

class ADualCombatColor_FPSProjectile;

UCLASS()
class DUALCOMBATCOLOR_FPS_API AActorObstacleCanyon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorObstacleCanyon();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ADualCombatColor_FPSProjectile> Projectile;


	UPROPERTY(EditAnywhere)
		float delayShoot;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CheckShoot();
	void Shoot();
};
