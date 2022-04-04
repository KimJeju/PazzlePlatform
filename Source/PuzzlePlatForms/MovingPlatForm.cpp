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

	if (HasAuthority()) // hasAuthority 앞에 !(Not)을 붙이면 서버에서 실행이 아닌 클라이언트에서 실행 (Not On Server == Client)
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Diraction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed * DeltaTime * Diraction;
		SetActorLocation(Location);
	}

	


}
