// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlatformPawn.generated.h"

UCLASS()
class DUALCOMBATCOLOR_FPS_API APlatformPawn : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY()
	FVector NewLocation;
	UPROPERTY()
	FRotator NewRotation;

	float RunningTime;
public:
	// Sets default values for this pawn's properties
	APlatformPawn();

	UPROPERTY(EditAnywhere)
		float wight;

	UPROPERTY(EditAnywhere)
		float length;

	bool bIsTread;

	// Movement Settings
	UPROPERTY(EditAnywhere)
		bool isStatic;

	UPROPERTY(EditAnywhere)
		bool canRotate;
	UPROPERTY(EditAnywhere)
		bool canMoveHorizontal;
	UPROPERTY(EditAnywhere)
		bool canMoveVertical;

	UPROPERTY(EditAnywhere)
		float moveHorizontalSpeed;
	UPROPERTY(EditAnywhere)
		float moveVerticalSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;

	UPROPERTY(EditAnywhere)
		float maxHeight;
	UPROPERTY(EditAnywhere)
		float maxHorizontal;
	UPROPERTY(EditAnywhere)
		float rotationDegrees;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	void Rotate(float DeltaTime);
	UFUNCTION()
	void MoveVertical(float DeltaTime);
	UFUNCTION()
	void MoveHorizontal(float DeltaTime);


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
