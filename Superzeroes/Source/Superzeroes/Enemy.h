// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnemySpawner.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API AEnemy : public APaperCharacter
{
protected:
	GENERATED_BODY()
	AEnemy();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void AI();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCharacterMovementComponent* characterMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* flipbookComponent;

	UFUNCTION(BlueprintCallable)
		void UpdateAnimation();

	UFUNCTION(BlueprintCallable)
		void UpdateRotation();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	UPROPERTY(VisibleAnywhere)
		float healthPoints;

	UPROPERTY(VisibleAnywhere)
		float damage;

	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> actorsToIgnore;

	UPROPERTY(VisibleAnywhere)
		AEnemySpawner* spawner;

	// Audio ariables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* jumpSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* deathSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* walkSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* hurtSFX;

	float walkSoundTimer;
	//This is so that the walk sound effect doesn't play every single frame
	//there may be a better way of doing this?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
		float TimeBetweenWalkSounds;

public:
	virtual void TakeEnemyDamage(float damage_);
	void AddToGetActorsToIgnore(AActor* actor) { actorsToIgnore.Add(actor); }
	void SetSpawner(AEnemySpawner* spawner_) { spawner = spawner_; }
};
