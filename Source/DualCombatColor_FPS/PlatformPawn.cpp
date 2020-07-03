// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPawn.h"

// Sets default values
APlatformPawn::APlatformPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsTread = false;

	isStatic = true;

	canRotate = true;
	canMoveHorizontal = true;
	canMoveVertical = true;

    moveHorizontalSpeed = 0;
    moveVerticalSpeed = 0;
    rotationSpeed = 0;

	maxHeight = 20.0f;
	maxHorizontal = 20.0f;
	rotationDegrees = 20.0f;

}

// Called when the game starts or when spawned
void APlatformPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlatformPawn::Rotate(float DeltaTime)
{
    if (canRotate)
    {
        float DeltaRotation = DeltaTime * rotationDegrees * rotationSpeed;
        NewRotation.Yaw += DeltaRotation;
    }

}

void APlatformPawn::MoveVertical(float DeltaTime)
{
    if (canMoveVertical)
    {
        float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
        NewLocation.Z += DeltaHeight * maxHeight * moveVerticalSpeed;
    }
}

void APlatformPawn::MoveHorizontal(float DeltaTime)
{
    if (canMoveHorizontal)
    {
        float DeltaHorizontal = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
        NewLocation.X += DeltaHorizontal * maxHorizontal * moveHorizontalSpeed;
    }
}

// Called every frame
void APlatformPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    NewLocation = GetActorLocation();
    NewRotation = GetActorRotation();
    RunningTime = GetGameTimeSinceCreation();

    if (!isStatic) 
    {
        MoveVertical(DeltaTime);
        MoveHorizontal(DeltaTime);
        Rotate(DeltaTime);
    }   
   
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

// Called to bind functionality to input
void APlatformPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

