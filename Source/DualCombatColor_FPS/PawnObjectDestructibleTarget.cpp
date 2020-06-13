// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnObjectDestructibleTarget.h"
#include "Engine/World.h"

// Sets default values
APawnObjectDestructibleTarget::APawnObjectDestructibleTarget()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnObjectDestructibleTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnObjectDestructibleTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnObjectDestructibleTarget::StartTimeLife()
{
	FTimerHandle UnsedHandle;
	GetWorldTimerManager().SetTimer(UnsedHandle, this, &APawnObjectDestructibleTarget::CheckLife, timeLife, false);
}
// Called to bind functionality to input
void APawnObjectDestructibleTarget::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void APawnObjectDestructibleTarget::CheckLife()
{
	if (bDestroyForTime)
	{
		Destroy();
	}
}

