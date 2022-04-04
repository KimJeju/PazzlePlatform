// Fill out your copyright notice in the Description page of Project Settings.
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
	
}

void AMovingPlatForm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) // hasAuthority �տ� !(Not)�� ���̸� �������� ������ �ƴ� Ŭ���̾�Ʈ���� ���� (Not On Server == Client)
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Diraction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed * DeltaTime * Diraction;
		SetActorLocation(Location);
	}

	


}
