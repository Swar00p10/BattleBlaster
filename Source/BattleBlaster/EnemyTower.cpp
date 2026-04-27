// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTower.h"

AEnemyTower::AEnemyTower()
{
}

void AEnemyTower::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle FireRateTimerHandle;
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemyTower::CheckFire, 2.0f, true);
}

void AEnemyTower::CheckFire()
{
	if (DetectionRange >= FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation()))
	{
		Fire();
	}

}

void AEnemyTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DetectionRange >= FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation()))
	{
		RotateTurret(PlayerTank->GetActorLocation());
	}	
}