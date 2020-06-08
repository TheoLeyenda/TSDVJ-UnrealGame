// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnObjectDestructibleTarget.generated.h"

UCLASS()
class DUALCOMBATCOLOR_FPS_API APawnObjectDestructibleTarget : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnObjectDestructibleTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		bool bDestroyForTime;

	UPROPERTY(EditAnywhere)
		float timeLife;

	void StartTimeLife();

	void CheckLife();
};
