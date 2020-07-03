// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorContainerWidget.generated.h"

class UUserWidget;

UCLASS()
class DUALCOMBATCOLOR_FPS_API AActorContainerWidget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorContainerWidget();

	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> SPlayer_Menu_Widget_Class;
	UUserWidget* SPlayer_Menu_Widget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
