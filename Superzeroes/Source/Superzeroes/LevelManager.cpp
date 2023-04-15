#include "LevelManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

ALevelManager::ALevelManager()
{
	boomBoom = nullptr;
	zipZap = nullptr;
	cameraComp = nullptr;
	boomBoomEnd = false;
	zipZapEnd = false;
	enemiesInitialized = false;
	currentLevel = 0;
}

void ALevelManager::BeginPlay()
{	
	Super::BeginPlay();
	SetActorTickEnabled(true);

	GetLevelTriggers();
	//GetEnemies();
	GetEnemySpawners();
	GetCameraComponent();
	InitializeLevelStartLocations();
	InitializeCameraLocations();
}

void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetCharacters();
	Checkhealth();
	GetEnemies();
}

void ALevelManager::GetCharacters()
{
	if (zipZap == nullptr || boomBoom == nullptr)
	{
		boomBoom = Cast<ABoomBoom>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass()));
		zipZap = Cast<AZipZap>(UGameplayStatics::GetActorOfClass(GetWorld(), AZipZap::StaticClass()));
	}
}

void ALevelManager::Checkhealth()
{
	if (zipZap && boomBoom)
	{
		if (zipZap->getHealth() <= 0.f && boomBoom->getHealth() <= 0.f)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("Sample2DLevel"));
		}
	}
}

void ALevelManager::GetLevelTriggers()
{
	TArray<AActor*> levelTriggers;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("LevelTrigger"), levelTriggers);

	for (AActor* trigger : levelTriggers)
	{
		trigger->OnActorBeginOverlap.AddDynamic(this, &ALevelManager::OverlapBegin);
		trigger->OnActorEndOverlap.AddDynamic(this, &ALevelManager::OverlapEnd);
	}

	levelTriggers.Empty();
}

void ALevelManager::GetEnemies()
{
	if (!enemiesInitialized)
	{
		TArray<AActor*> enemyActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemyActors);

		for (AActor* enemy : enemyActors)
		{
			enemy->SetActorTickEnabled(false);
			enemies.Add(Cast<AEnemy>(enemy));
		}

		enemyActors.Empty();
		enemiesInitialized = true;
	}
}

void ALevelManager::GetEnemySpawners()
{
	TArray<AActor*> enemySpawnerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), enemySpawnerActors);

	for (AActor* spawner : enemySpawnerActors)
	{
		spawner->SetActorTickEnabled(false);
		enemySpawners.Add(Cast<AEnemySpawner>(spawner));
	}

	enemySpawnerActors.Empty();
}

void ALevelManager::GetCameraComponent()
{
	TArray<AActor*> cameraActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Camera"), cameraActors);
	cameraComp = cameraActors[0]->GetRootComponent();
	cameraActors.Empty();
}

void ALevelManager::InitializeLevelStartLocations()
{
	// Initialize level start locations
	levelStartLocations.Add(FVector(1058.f, .5f, -378.f));
	levelStartLocations.Add(FVector(3043.f, .5f, -58.f));
	levelStartLocations.Add(FVector(5028.f, .5f, -378.f));
	levelStartLocations.Add(FVector(7050.f, .5f, 42.f));
	levelStartLocations.Add(FVector(7120.f, .5f, 1005.f));
	levelStartLocations.Add(FVector(7420.f, .5f, 1592.f));
	levelStartLocations.Add(FVector(9410.f, .5f, 2092.f));
}

void ALevelManager::InitializeCameraLocations()
{
	// Initialize camera positions
	cameraLocations.Add(FVector(1990.f, 1000.f, 0.f)); // Where will the correponsing trigger take the camera (from level 0 to level 1 in this case; trigger 0 will take it to the position that is intended for level 1) 
	cameraLocations.Add(FVector(3980.f, 1000.f, 0.f));
	cameraLocations.Add(FVector(5970.f, 1000.f, 0.f));
	cameraLocations.Add(FVector(7960.f, 1000.f, 500.f));
	cameraLocations.Add(FVector(6370.f, 1000.f, 1430.f));
	cameraLocations.Add(FVector(8360.f, 1000.f, 1950.f));
	cameraLocations.Add(FVector(10340.f, 1000.f, 1950.f));
}

void ALevelManager::SwitchToNextLevel(AActor* triggerToDestroy)
{
	// Get trigger index
	int triggerNum = UKismetStringLibrary::Conv_StringToInt(triggerToDestroy->Tags[1].ToString());
	currentLevel++;

	// Move camera and characters
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.Linkage = 0;
	LatentInfo.UUID = 0;

	if (currentLevel == 8)
	{
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
	}

	UKismetSystemLibrary::MoveComponentTo(cameraComp, cameraLocations[triggerNum], cameraComp->GetComponentRotation(), true, true, 0.2f, false, EMoveComponentAction::Move, LatentInfo);
	LatentInfo.UUID = 1;
	UKismetSystemLibrary::MoveComponentTo(boomBoom->GetRootComponent(), levelStartLocations[triggerNum], boomBoom->GetRootComponent()->GetComponentRotation(), true, true, 0.2f, false, EMoveComponentAction::Move, LatentInfo);
	LatentInfo.UUID = 2;
	UKismetSystemLibrary::MoveComponentTo(zipZap->GetRootComponent(), FVector(levelStartLocations[triggerNum].X + 120.f, levelStartLocations[triggerNum].Y, levelStartLocations[triggerNum].Z - 23.281904f), zipZap->GetRootComponent()->GetComponentRotation(), true, true, 0.2f, false, EMoveComponentAction::Move, LatentInfo);

	// Set characters' level indexes
	boomBoom->SetLevelIndex(currentLevel);;
	zipZap->SetLevelIndex(currentLevel);

	// Destroy the trigger
	triggerToDestroy->Destroy();

	// Activate enemies
	for (AEnemy* enemy : enemies)
	{
		int enemyLevelNum = UKismetStringLibrary::Conv_StringToInt(enemy->Tags[1].ToString());

		if (enemyLevelNum == currentLevel)
		{
			enemy->SetActorTickEnabled(true);
		}
	}

	// Activate spawners
	for (AEnemySpawner* spawner : enemySpawners)
	{
		int enemySpawnerLevelNum = UKismetStringLibrary::Conv_StringToInt(spawner->Tags[0].ToString());

		if (enemySpawnerLevelNum == currentLevel)
		{
			spawner->SetActorTickEnabled(true);
		}
	}
}

void ALevelManager::OverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor->IsA(ABoomBoom::StaticClass()))
	{
		boomBoomEnd = true;

		if (zipZapEnd)
		{
			SwitchToNextLevel(overlappedActor);
		}
	}

	if (otherActor->IsA(AZipZap::StaticClass()))
	{
		zipZapEnd = true;

		if (boomBoomEnd)
		{
			SwitchToNextLevel(overlappedActor);
		}
	}
}

void ALevelManager::OverlapEnd(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor->IsA(ABoomBoom::StaticClass()))
	{
		boomBoomEnd = false;
	}

	if (otherActor->IsA(AZipZap::StaticClass()))
	{
		zipZapEnd = false;
	}
}