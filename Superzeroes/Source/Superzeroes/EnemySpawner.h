// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "EnemySpawner.generated.h"

#define SpawnTimeout 1;

UCLASS()
class SUPERZEROES_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

protected:
	AEnemySpawner();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void SpawnEnemy();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AEnemy> EnemyClass;

	UPROPERTY(VisibleAnywhere)
		TArray<AEnemy*> enemies;

	UPROPERTY(VisibleAnywhere)
		float spawnTimer;
};
