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
	trashCansInitialized = false;
	currentLevel = 0;
}

void ALevelManager::BeginPlay()
{	
	Super::BeginPlay();
	SetActorTickEnabled(true);

	GetLevelTriggers();
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
	GetTrashCans();
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

void ALevelManager::GetTrashCans()
{
	if (!trashCansInitialized)
	{
		TArray<AActor*> trashCanActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrashCan::StaticClass(), trashCanActors);

		for (AActor* trashCan : trashCanActors)
		{
			trashCan->SetActorTickEnabled(false);
			trashCans.Add(Cast<ATrashCan>(trashCan));
		}

		trashCanActors.Empty();
		trashCansInitialized = true;
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
	levelStartLocations.Add(FVector(1058.f, .5f, -400.f)); //2
	levelStartLocations.Add(FVector(3043.f, .5f, -58.f)); //3
	levelStartLocations.Add(FVector(5028.f, .5f, -400.f)); //4
	levelStartLocations.Add(FVector(7008.f, .5f, -400.f)); //5
	levelStartLocations.Add(FVector(8998.f, .5f, -400.f)); //6
	levelStartLocations.Add(FVector(10978.f, .5f, 50.f)); //7
	levelStartLocations.Add(FVector(10948.f, .5f, 880.f)); //8
	levelStartLocations.Add(FVector(11178.f, .5f, 1580.f)); //9
	levelStartLocations.Add(FVector(13168.f, .5f, 2080.f)); //10
	levelStartLocations.Add(FVector(15148.f, .5f, 1580.f)); //11
	levelStartLocations.Add(FVector(17098.f, .5f, 860.f)); //12
	levelStartLocations.Add(FVector(19128.f, .5f, 320.f)); //13
	levelStartLocations.Add(FVector(21128.f, .5f, 290.f)); //14
	levelStartLocations.Add(FVector(23078.f, .5f, 660.f)); //15
	levelStartLocations.Add(FVector(25068.f, .5f, 930.f)); //16
	levelStartLocations.Add(FVector(27048.f, .5f, 1590.f)); //17
}

void ALevelManager::InitializeCameraLocations()
{
	// Initialize camera positions
	cameraLocations.Add(FVector(1990.f, 1000.f, 0.f)); //2 // Where will the correponsing trigger take the camera (from level 0 to level 1 in this case; trigger 0 will take it to the position that is intended for level 1) 
	cameraLocations.Add(FVector(3980.f, 1000.f, 0.f)); //3
	cameraLocations.Add(FVector(5970.f, 1000.f, 0.f)); //4
	cameraLocations.Add(FVector(7940.f, 1000.f, 0.f)); //5
	cameraLocations.Add(FVector(9930.f, 1000.f, 0.f)); //6
	cameraLocations.Add(FVector(11920.f, 1000.f, 500.f)); //7
	cameraLocations.Add(FVector(10120.f, 1000.f, 1300.f)); //8
	cameraLocations.Add(FVector(12110.f, 1000.f, 2000.f)); //9
	cameraLocations.Add(FVector(14100.f, 1000.f, 2000.f)); //10
	cameraLocations.Add(FVector(16070.f, 1000.f, 1310.f)); //11
	cameraLocations.Add(FVector(18060.f, 1000.f, 700.f)); //12
	cameraLocations.Add(FVector(20040.f, 1000.f, 700.f)); //13
	cameraLocations.Add(FVector(22030.f, 1000.f, 700.f)); //14
	cameraLocations.Add(FVector(24020.f, 1000.f, 700.f)); //15
	cameraLocations.Add(FVector(26000.f, 1000.f, 1330.f)); //16
	cameraLocations.Add(FVector(27990.f, 1000.f, 1980.f)); //17
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

	if (currentLevel == 17)
	{
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("Final_Cinematic"));
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
		else if (enemyLevelNum < currentLevel)
		{
			enemy->TakeEnemyDamage(200.f);
		}
	}

	//Activate trash cans
	for (ATrashCan* trash : trashCans)
	{
		int trashCanLevelNum = UKismetStringLibrary::Conv_StringToInt(trash->Tags[1].ToString());

		if (trashCanLevelNum == currentLevel)
		{
			trash->SetActorTickEnabled(true);
		}
	}

	// Activate spawners
	for (AEnemySpawner* spawner : enemySpawners)
	{
		int enemySpawnerLevelNum = UKismetStringLibrary::Conv_StringToInt(spawner->Tags[0].ToString());
		if (enemySpawnerLevelNum == currentLevel)
		{
			spawner->SetActorTickEnabled(true);
			enemySpawners.Remove(spawner);
		}
	}

	// Remove burger
	TArray<AActor*> burger;
	FString tag_ = "Burger ";
	tag_.Append(FString::FromInt(currentLevel - 1));
	FName burgerTag = FName(*tag_);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), burgerTag, burger);
	for (AActor* actor : burger)
	{
		actor->Destroy();
	}
}

void ALevelManager::OverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor->IsA(ABoomBoom::StaticClass()))
	{
		if (Cast<ABoomBoom>(otherActor)->GetState() != BB_State::Siege)
		{
			boomBoomEnd = true;
			boomBoom->EnableLevelFinishedParticle();

			if (zipZapEnd)
			{
				SwitchToNextLevel(overlappedActor);
			}
		}
	}

	if (otherActor->IsA(AZipZap::StaticClass()))
	{
		if (Cast<AZipZap>(otherActor)->GetState() != ZZ_State::Siege)
		{
			zipZapEnd = true;
			zipZap->EnableLevelFinishedParticle();

			if (boomBoomEnd)
			{
				SwitchToNextLevel(overlappedActor);
			}
		}
	}
}

void ALevelManager::OverlapEnd(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor->IsA(ABoomBoom::StaticClass()))
	{
		boomBoomEnd = false;
		boomBoom->DisableLevelFinishedParticle();
	}

	if (otherActor->IsA(AZipZap::StaticClass()))
	{
		zipZapEnd = false;
		zipZap->DisableLevelFinishedParticle();
	}
}