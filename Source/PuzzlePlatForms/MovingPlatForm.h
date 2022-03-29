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

	virtual void Tick(float DeltaTime) override;
};
