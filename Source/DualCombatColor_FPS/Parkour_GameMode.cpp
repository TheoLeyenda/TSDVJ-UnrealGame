#include "Parkour_GameMode.h"
#include "Engine/World.h"
#include "PlatformPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AssetLoaderManager.h"
AParkour_GameMode::AParkour_GameMode() 
{
}
void AParkour_GameMode::Tick(float DeltaTime)
{
}

void AParkour_GameMode::BeginPlay()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), platformPawn_Class, actorPlatforms);
	for (AActor* actor : actorPlatforms)
	{
		if (actor != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hola Actors:D"));
			refPlatforms.Add(Cast<APlatformPawn>(actor));
		}
	}
	for (APlatformPawn* refplatform : refPlatforms)
	{
		if (refplatform != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hola Platforms :D"));
			FVector position = GetRandomPosition(refplatform->length, refplatform->wight, refplatform->GetActorTransform().GetLocation().Z + 10);
			FRotator rotator = refplatform->GetActorRotation();
			//Spawning objects

		}
	}
	//Carga El Asset de forma Asyncronica//
	AAssetLoaderManager* AssetLoader = Cast<AAssetLoaderManager>(AAssetLoaderManager::StaticClass()->GetDefaultObject());
	AssetLoader->LoadAssets();
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("AssetLoadStart"));
	//----------------------------------//
}
FVector AParkour_GameMode::GetRandomPosition(float maxLength, float maxWight, float hight)
{
	return FVector(FMath::RandRange(-maxLength, maxLength), hight, FMath::RandRange(-maxWight, maxWight));
}