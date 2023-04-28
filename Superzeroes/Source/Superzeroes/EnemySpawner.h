// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SUPERZEROES_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnEnemy();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AEnemy> EnemyClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AComicFX> comicFX;

	UPROPERTY(VisibleAnywhere)
		TArray<class AEnemy*> enemies;

	UPROPERTY(VisibleAnywhere)
		float spawnTimer;

	UPROPERTY(EditAnywhere)
		float timeout;

	UPROPERTY(EditAnywhere)
		int count;

	UPROPERTY(EditAnywhere)
		bool isInfinite;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void RemoveEnemy(AEnemy* enemy) { enemies.Remove(enemy); }
};
