// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorObstacleRay.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "DualCombatColor_FPSCharacter.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"
#include "UI_PlayerWidget.h"

// Sets default values
AActorObstacleRay::AActorObstacleRay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActorObstacleRay::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorObstacleRay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckShootRay();
	
}
void AActorObstacleRay::CheckShootRay()
{
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	const FVector& StartPosition = GetActorLocation();
	FVector EndPosition = GetActorLocation() + GetActorUpVector() * TraceDistance;

	FHitResult HitResult;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPosition, EndPosition, TraceChannel, QueryParams))
	{
		if (HitResult.Actor.IsValid())
		{
			if (HitResult.GetActor()->Tags[0] == FName(TEXT("Player")))
			{
				ADualCombatColor_FPSCharacter* Player = Cast<ADualCombatColor_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				if (Player != nullptr)
				{
					Player->dataPlayer.life = Player->dataPlayer.life - Damage;
					Player->UI_PlayerWidget->SetCurrentLifeText(Player->dataPlayer.life);

					Destroy();
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Player de ActorObstacleRay Nulo"));
				}
				//ADualCombatColor_FPSCharacter* Player = Cast<ADualCombatColor_FPSCharacter>(HitResult.GetActor());
				UE_LOG(LogTemp, Warning, TEXT("Hit Jugador"));
			}
		}
	}
	UKismetSystemLibrary::DrawDebugLine(this, StartPosition, EndPosition, FLinearColor::Red, 5.0f);
}

