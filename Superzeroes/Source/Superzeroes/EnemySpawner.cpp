// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "ComicFX.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	timeout = 0.f;
	count = 0;
	spawnTimer = 0;
	isInfinite = false;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	spawnTimer = timeout;
	spriteComponent = FindComponentByClass<UPaperSpriteComponent>();

	if (!isInfinite)
	{
		spriteComponent->SetSprite(numberSprites[count]);
	}
}

void AEnemySpawner::SpawnEnemy()
{
	AEnemy* spawn = GetWorld()->SpawnActor<AEnemy>(EnemyClass, GetActorLocation(), FRotator(0.f, 0.f, 0.f));

	if (IsValid(spawn))
	{
		spawn->SpawnDefaultController();
		enemies.Add(spawn);
		spawn->LaunchCharacter(FVector(200.f, 100.f, 0.f), false, false);
	}

	if (!isInfinite)
	{
		spriteComponent->SetSprite(numberSprites[count]);
	}

	for (AEnemy* enemy : enemies)
	{
		if (IsValid(enemy))
		{
			enemy->AddToGetActorsToIgnore(enemy->GetOwner());
				enemy->SetSpawner(this);
		}
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
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