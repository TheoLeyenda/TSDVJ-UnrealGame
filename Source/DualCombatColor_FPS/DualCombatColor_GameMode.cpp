// Fill out your copyright notice in the Description page of Project Settings.


#include "DualCombatColor_GameMode.h"
#include "GameFramework/Actor.h" 
#include "Engine/World.h"
#include "PawnObjectDestructibleTarget.h"

ADualCombatColor_GameMode::ADualCombatColor_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADualCombatColor_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADualCombatColor_GameMode::BeginPlay()
{
	Super::BeginPlay();
	StartNextRound();
}
void ADualCombatColor_GameMode::StartGame()
{
	SpawnObject();
	FTimerHandle UnsedHandle;
	GetWorldTimerManager().SetTimer(UnsedHandle, this, &ADualCombatColor_GameMode::ResultRound, timeRound, false);
}
/*void ADualCombatColor_GameMode::DestroyObjects()
{
	for(AActor* actors : instantiatedObjects)
	{
		if (actors != nullptr) 
		{
			AActor* actor = actors;
			instantiatedObjects.Remove(actors);
			actor->Destroy();
		}
	}
}*/
void ADualCombatColor_GameMode::ResultRound()
{
	//DestroyObjects();

	//Checkea el resultado de la ronda sumando un punto al jugador correspondiente.
	//Checkea si el puntaje del jugador (rondas ganadas) es igual a la cantidad de rondas nesesarias para ganar la partida.

	//(if)Si el puntaje del jugador (rondas ganadas) es mayor o igual a la cantidad de rondas nesesarias para ganar se muestra la pantalla de "¡Ganaste!" del jugador que gano junto con todas sus estadisticas.

	//(else if)Si el jugador perdio se muestran sus estadisticas junto con su pantalla de "¡Perdiste :D!"

	//(else) si las anteriores dos condiciones no se cumplen quiere decir que la partida no termino y empieza la siguiente ronda
	StartNextRound();
}

void ADualCombatColor_GameMode::ResetPositionPlayer()
{
	//Resetea la posicion del jugador
}

void ADualCombatColor_GameMode::StartNextRound()
{
	ResetPositionPlayer();
	FTimerHandle UnsedHandle;
	GetWorldTimerManager().SetTimer(UnsedHandle, this, &ADualCombatColor_GameMode::StartGame, startDelayRound, false);
}
void ADualCombatColor_GameMode::SpawnObject()
{
	UWorld* world = GetWorld();
	FRotator spawnRotator;
	FVector spawnPosition;
	int i = 0;
	int countTeamBlueGenerated = 0;
	int countTeamRedGenerated = 0;
	bool GeneratedRedy = false;
	while (!GeneratedRedy)
	{
		APawnObjectDestructibleTarget* PawnObjectDestructibleTarget;

		if (countTeamBlueGenerated < countObjectsForRound) 
		{
			spawnRotator = GetRandomRotator();
			spawnPosition = GetRandomPosition();
			PawnObjectDestructibleTarget = world->SpawnActor<APawnObjectDestructibleTarget>(cuboAzul, spawnPosition, spawnRotator);

			if (PawnObjectDestructibleTarget != nullptr)
			{
				PawnObjectDestructibleTarget->bDestroyForTime = true;
				PawnObjectDestructibleTarget->timeLife = timeRound - 0.2;
				PawnObjectDestructibleTarget->StartTimeLife();
				countTeamBlueGenerated++;
			}
		}

		if (countTeamRedGenerated < countObjectsForRound)
		{
			spawnRotator = GetRandomRotator();
			spawnPosition = GetRandomPosition();
			PawnObjectDestructibleTarget = world->SpawnActor<APawnObjectDestructibleTarget>(cuboRojo, spawnPosition, spawnRotator);

			if (PawnObjectDestructibleTarget != nullptr)
			{
				PawnObjectDestructibleTarget->bDestroyForTime = true;
				PawnObjectDestructibleTarget->timeLife = timeRound - 0.2;
				PawnObjectDestructibleTarget->StartTimeLife();
				countTeamRedGenerated++;
			}
		}

		GeneratedRedy = (countTeamBlueGenerated >= countObjectsForRound && countTeamRedGenerated >= countObjectsForRound);
	}

	//UE_LOG(LogTemp, Warning, TEXT("FLACO SE SPAWNEO TU TORUS"));

	/*UWorld* world = GetWorld();

	const FRotator SpawnRotation = FRotator(.0f, .0f, .0f);
	const FVector SpawnLocation = FVector(5.0f, 5.0f, 50.0f);
	world->SpawnActor<AActor>(RedCube, SpawnLocation, SpawnRotation);
	UE_LOG(LogTemp, Warning, TEXT("FLACO SE SPAWNEO TU TORUS"));*/

}
FVector ADualCombatColor_GameMode::GetRandomPosition()
{
	return FVector(FMath::RandRange(minCoord_X, maxCoord_X), FMath::RandRange(minCoord_Y, maxCoord_Y), coord_Z);
}
FRotator ADualCombatColor_GameMode::GetRandomRotator()
{
	return FRotator(FMath::RandRange(minRotation_X, maxRotation_X), FMath::RandRange(minRotation_Y, maxRotation_Y), FMath::RandRange(minRotation_Z, maxRotation_Z));
}
