// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorContainerWidget.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AActorContainerWidget::AActorContainerWidget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorContainerWidget::BeginPlay()
{
	Super::BeginPlay();
	if (SPlayer_Menu_Widget_Class != nullptr)
	{
		SPlayer_Menu_Widget = CreateWidget(GetWorld(), SPlayer_Menu_Widget_Class);
		SPlayer_Menu_Widget->AddToViewport();
	}
	
}

// Called every frame
void AActorContainerWidget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

