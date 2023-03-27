// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

#define SpawnTimeout 5;

class AEnemy;

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

public:
	void RemoveEnemy(AEnemy* enemy) { enemies.Remove(enemy); }
};
