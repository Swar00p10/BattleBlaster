// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleBlasterGamemode.h"
#include "EnemyTower.h"
#include "Kismet/GameplayStatics.h"

void ABattleBlasterGamemode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> EnemyTowers;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTower::StaticClass(), EnemyTowers);
	EnemyTowerCount = EnemyTowers.Num();
	UE_LOG(LogTemp, Warning, TEXT("Enemy Tower Count: %i"), EnemyTowerCount);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		PlayerTank = Cast<APlayerTank>(PlayerPawn);	
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("GameMode: Failed to find the PlayerTank"));
		}
	}

	for(int i = 0; i < EnemyTowerCount; i++)
	{
		AEnemyTower* EnemyTower = Cast<AEnemyTower>(EnemyTowers[i]);
		if (EnemyTower)
		{
			EnemyTower->PlayerTank = PlayerTank;
			UE_LOG(LogTemp, Warning, TEXT("GameMode: setting tank varible"));
		}
	}
}