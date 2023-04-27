// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner3.h"
#include "Enemy.h"
#include "ComicFX.h"

// Sets default values
AEnemySpawner3::AEnemySpawner3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	timeout = 0.f;
	count = 0;
	spawnTimer = 0;
	isInfinite = false;
}

// Called when the game starts or when spawned
void AEnemySpawner3::BeginPlay()
{
	Super::BeginPlay();
	
	spawnTimer = timeout;
}

void AEnemySpawner3::SpawnEnemy()
{
	AEnemy* spawn = GetWorld()->SpawnActor<AEnemy>(EnemyClass, GetActorLocation(), FRotator(0.f, 0.f, 0.f));
	spawn->SpawnDefaultController();
	enemies.Add(spawn);
	spawn->LaunchCharacter(FVector(200.f, 100.f, 0.f), false, false);

	if (!isInfinite)
	{
		AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, GetActorLocation(), GetActorRotation());
		cfx->spriteChanger(count + 6);
	}

	for (AEnemy* enemy : enemies)
	{
		spawn->AddToGetActorsToIgnore(enemy->GetOwner());
		spawn->SetSpawner(this);
	}
}

// Called every frame
void AEnemySpawner3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (spawnTimer > 0.f)
	{
		spawnTimer -= DeltaTime;
	}
	else
	{
		if (!isInfinite)
		{
			if (count > 0)
			{
				count--;
				SpawnEnemy();
			}
		}
		else
		{
			SpawnEnemy();
		}

		spawnTimer = timeout;
	}

	if (count <= 0)
	{
		Destroy();
	}
}