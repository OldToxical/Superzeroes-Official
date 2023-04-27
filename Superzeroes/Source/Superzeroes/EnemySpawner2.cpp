// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner2.h"

// Sets default values
AEnemySpawner2::AEnemySpawner2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//spawnTimeout = 0.f;
	//spawnCount = 0;
	//spawnTimer = 0;
	//endlessSpawning = false;
}

// Called when the game starts or when spawned
void AEnemySpawner2::BeginPlay()
{
	Super::BeginPlay();

	//spawnTimer = spawnTimeout;
}

/*void AEnemySpawner2::SpawnEnemy()
{
	AEnemy* spawn = GetWorld()->SpawnActor<AEnemy>(EnemyClass, GetActorLocation(), FRotator(0.f, 0.f, 0.f));
	spawn->SpawnDefaultController();
	enemies.Add(spawn);
	spawn->LaunchCharacter(FVector(200.f, 100.f, 0.f), false, false);

	if (!endlessSpawning)
	{
		AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, GetActorLocation(), GetActorRotation());
		cfx->spriteChanger(spawnCount + 6);
	}

	for (AEnemy* enemy : enemies)
	{
		spawn->AddToGetActorsToIgnore(enemy->GetOwner());
		spawn->SetSpawner(this);
	}
}*/

// Called every frame
void AEnemySpawner2::Tick(float DeltaTime)
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
				//SpawnEnemy();
			}
		}
		else
		{
			//SpawnEnemy();
		}

		//spawnTimer = spawnTimeout;
	}
}

