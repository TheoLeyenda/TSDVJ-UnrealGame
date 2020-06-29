// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Parkour_GameMode.generated.h"

/**
 * 
 */
class APlatformPawn;
class AActor;
UCLASS()
class DUALCOMBATCOLOR_FPS_API AParkour_GameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AParkour_GameMode();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APlatformPawn> platformPawn_Class;


	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
		//TArray<TSubclassOf<APlatformPawn>> platforms;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<APawn> trap;
	
	FVector GetRandomPosition(float maxLength, float maxWight, float hight);
	
	UPROPERTY()
		TArray<AActor*> actorPlatforms;

	UPROPERTY(EditAnywhere)
		TArray<APlatformPawn*> refPlatforms;
};

