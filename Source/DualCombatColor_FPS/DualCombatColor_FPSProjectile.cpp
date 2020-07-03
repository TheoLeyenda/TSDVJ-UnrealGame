// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DualCombatColor_FPSProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DualCombatColor_FPSCharacter.h"
#include "UI_PlayerWidget.h"

ADualCombatColor_FPSProjectile::ADualCombatColor_FPSProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ADualCombatColor_FPSProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ADualCombatColor_FPSProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if (OtherActor != NULL) 
	{
		if (OtherActor->ActorHasTag("Pared") && !bShooterPlayer) 
		{
			Destroy();
		}
		if (OtherActor->ActorHasTag("Player") && !bShooterPlayer) 
		{
			ADualCombatColor_FPSCharacter* Player = Cast<ADualCombatColor_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			if (Player != nullptr)
			{
				Player->FdataPlayer.life = Player->FdataPlayer.life - damageBullet;
				Player->UI_PlayerWidget->SetCurrentLifeText(Player->FdataPlayer.life);

				Destroy();
			}
		}
	}
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
}