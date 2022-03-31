// Fill out your copyright notice in the Description page of Project Settings.
#include "MovingPlatForm.h"


AMovingPlatForm::AMovingPlatForm()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatForm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location =GetActorLocation();
	Location += FVector(5 * DeltaTime, 0, 0);
	SetActorLocation(Location);
}
