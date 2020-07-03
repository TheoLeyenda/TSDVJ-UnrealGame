// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class DUALCOMBATCOLOR_FPS_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    AMovePlatform();

    UPROPERTY(EditAnywhere)
        bool canRotate;
    UPROPERTY(EditAnywhere)
        bool canMoveHorizontal;
    UPROPERTY(EditAnywhere)
        bool canMoveVertical;

    UPROPERTY(EditAnywhere)
        float maxHeight;

    UPROPERTY(EditAnywhere)
        float maxHorizontal;

    UPROPERTY(EditAnywhere)
        float rotationDegrees;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
