// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatForm.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatForm : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatForm(); 

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float Speed = 20;

	UPROPERTY(EditAnywhere)
		FVector TargetLocation;
		
private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};
