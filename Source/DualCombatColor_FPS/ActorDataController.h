// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorDataController.generated.h"

UCLASS()
class DUALCOMBATCOLOR_FPS_API AActorDataController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorDataController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
		bool bResetDataGameInstance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
