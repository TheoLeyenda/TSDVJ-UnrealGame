// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorObstacleCanyon.h"
#include "Engine/World.h"
#include "DualCombatColor_FPSProjectile.h"

// Sets default values
AActorObstacleCanyon::AActorObstacleCanyon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorObstacleCanyon::BeginPlay()
{
	Super::BeginPlay();
	CheckShoot();
}

// Called every frame
void AActorObstacleCanyon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AActorObstacleCanyon::CheckShoot() 
{
	FTimerHandle UnsedHandle;
	GetWorldTimerManager().SetTimer(UnsedHandle, this, &AActorObstacleCanyon::Shoot, delayShoot, true);
}
void AActorObstacleCanyon::Shoot() 
{
	ADualCombatColor_FPSProjectile* RefProjectile;
	RefProjectile = GetWorld()->SpawnActor<ADualCombatColor_FPSProjectile>(Projectile, GetActorLocation(), GetActorRotation());
	RefProjectile->bShooterPlayer = true;
}

