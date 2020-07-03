// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorDataController.h"
#include "ParkourGameInstance.h"

// Sets default values
AActorDataController::AActorDataController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorDataController::BeginPlay()
{
	Super::BeginPlay();
	if (bResetDataGameInstance) 
	{
		UParkourGameInstance* parkourGameInstance = Cast<UParkourGameInstance>(GetGameInstance());
		parkourGameInstance->currentData.currentScore = 0;
		parkourGameInstance->currentData.currentLevel = 1;

	}
}

// Called every frame
void AActorDataController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

