// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerTank.h"

#include "BattleBlasterGamemode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEBLASTER_API ABattleBlasterGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	APlayerTank* PlayerTank = nullptr;
	int16 EnemyTowerCount = 0;
};
