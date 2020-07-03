#include "MovePlatform.h"

// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

    canRotate = true;
    canMoveHorizontal = true;
    canMoveVertical = true;

    maxHeight = 20.0f;
    maxHorizontal = 20.0f;
    rotationDegrees = 20.0f;
	
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();

    float RunningTime = GetGameTimeSinceCreation();

    if (canMoveHorizontal) 
    {
        float DeltaHorizontal = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
        NewLocation.X += DeltaHorizontal * maxHorizontal;
    }
    
    if (canMoveVertical)
    {
        float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
        NewLocation.Z += DeltaHeight * maxHeight;
    }
    
    if (canRotate)
    {
        float DeltaRotation = DeltaTime * rotationDegrees;
        NewRotation.Yaw += DeltaRotation;
    }

    SetActorLocationAndRotation(NewLocation, NewRotation);
}



