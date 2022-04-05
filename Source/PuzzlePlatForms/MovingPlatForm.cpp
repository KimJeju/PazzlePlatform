// Fill out your copyright notice in the Description page of Project Settings.
// C++ develop
#include "MovingPlatForm.h"


AMovingPlatForm::AMovingPlatForm()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void  AMovingPlatForm::BeginPlay()
{
	Super::BeginPlay();


	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
}

void AMovingPlatForm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) // hasAuthority �տ� !(Not)�� ���̸� �������� ������ �ƴ� Ŭ���̾�Ʈ���� ���� (Not On Server == Client)
	{
		FVector Location = GetActorLocation();
		float JourneyLenth = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLenth)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Diraction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Speed * DeltaTime * Diraction;
		SetActorLocation(Location);
	}

	


}
