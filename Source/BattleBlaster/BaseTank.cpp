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

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TankTurretMesh);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

}

void ABaseTank::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TankTurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.0f, ToTarget.Rotation().Yaw, 0.0f);
	
	TankTurretMesh->SetWorldRotation(FMath::RInterpConstantTo(TankTurretMesh->GetComponentRotation(), LookAtRotation, GetWorld()->GetDeltaSeconds(), 500.0f));
	
}

void ABaseTank::Fire()
{
	FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();


	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
	if (Projectile)
	{
		Projectile->SetOwner(this);
		UE_LOG(LogTemp, Warning, TEXT("Owner is %s"), *Projectile->GetOwner()->GetActorNameOrLabel());
	}
	//DrawDebugSphere(GetWorld(), SpawnLocation, 25.0f, 12, FColor::Green, false, 3.0f);

}



