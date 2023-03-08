// Fill out your copyright notice in the Description page of Project Settings.
#include "EnemySpawner.h"
#include "Enemy.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnemyClass = NULL;
	spawnTimer = SpawnTimeout;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (spawnTimer > 0.f)
	{
		spawnTimer -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		if (enemies.Num() < 2)
		{
			SpawnEnemy();
		}

		spawnTimer = SpawnTimeout;
	}
}

void AEnemySpawner::SpawnEnemy()
{
	AEnemy* spawn = GetWorld()->SpawnActor<AEnemy>(EnemyClass, GetActorLocation(), FRotator(0.f, 0.f, 0.f));
	spawn->SpawnDefaultController();
	enemies.Add(spawn);
	spawn->LaunchCharacter(FVector(200.f, 100.f, 0.f), false, false);

	for (AEnemy* enemy : enemies)
	{
		spawn->AddToGetActorsToIgnore(enemy->GetOwner());
		spawn->SetSpawner(this);
	}
}