// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTank.h"

// Sets default values
ABaseTank::ABaseTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BaseCollisionComponent"));
	SetRootComponent(CapsuleCollisionComponent);

	TankBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMeshComponent"));
	TankBaseMesh->SetupAttachment(CapsuleCollisionComponent);

	TankTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMeshComponent"));
	TankTurretMesh->SetupAttachment(TankBaseMesh);

}

void ABaseTank::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TankTurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.0f, ToTarget.Rotation().Yaw, 0.0f);
	
	TankTurretMesh->SetWorldRotation(FMath::RInterpConstantTo(TankTurretMesh->GetComponentRotation(), LookAtRotation, GetWorld()->GetDeltaSeconds(), 500.0f));
}



