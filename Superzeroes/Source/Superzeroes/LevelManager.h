// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "TrashCan.h"
#include "LevelManager.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ALevelManager : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	void RemoveEnemy(AEnemy* enemy) { enemies.Remove(enemy); }
	void RemoveTrashCan(ATrashCan* trash) { trashCans.Remove(trash); }
	
protected:
	ALevelManager();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	void GetCharacters();
	void Checkhealth();
	void SwitchToNextLevel(AActor* triggerToDestroy);
	void GetLevelTriggers();
	void GetEnemies();
	void GetTrashCans();
	void GetEnemySpawners();
	void GetCameraComponent();
	void InitializeLevelStartLocations();
	void InitializeCameraLocations();

	UFUNCTION(BlueprintCallable)
		void OverlapBegin(AActor* overlappedActor, AActor* otherActor);

	UFUNCTION(BlueprintCallable)
		void OverlapEnd(AActor* overlappedActor, AActor* otherActor);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		ABoomBoom* boomBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* cameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FVector> cameraLocations;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FVector> levelStartLocations;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<AEnemy*> enemies;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<AEnemySpawner*> enemySpawners;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<ATrashCan*> trashCans;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int currentLevel;

	bool boomBoomEnd;
	bool zipZapEnd;
	bool enemiesInitialized;
	bool trashCansInitialized;
};
