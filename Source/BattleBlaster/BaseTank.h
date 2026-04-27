// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "HealthComponent.h"

#include "BaseTank.generated.h"

UCLASS()
class BATTLEBLASTER_API ABaseTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseTank();

public:	

	UPROPERTY(VisibleAnywhere,Category = "Components")
	UCapsuleComponent* CapsuleCollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *TankBaseMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *TankTurretMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Components")
	UHealthComponent* HealthComponent;

	void RotateTurret(FVector LookAtTarget);


	virtual void Fire();
};
