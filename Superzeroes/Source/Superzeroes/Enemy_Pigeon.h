// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Enemy_Pigeon.generated.h"

#define MinimumDistanceToGetIntoCombatX 500
#define MinimumDistanceToGetIntoCombatZ 40
#define ShootingAnimationLength 0.6

class ABoomBoom;
class AZipZap;
class AProjectile;

enum State3
{
	Idle,
	Jumping,
	WalkingLeft,
	WalkingRight,
	Attacking,
	Dead
};

enum Action
{
	GoIdle,
	Jump,
	WalkLeft,
	WalkRight,
	Attack
};

UCLASS()
class SUPERZEROES_API AEnemy_Pigeon : public AEnemy
{
	GENERATED_BODY()

private:
	AEnemy_Pigeon();

	virtual void AI() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void TakeEnemyDamage(float damage_);

	// AI Functions
	void GetState();
	void ChooseAction();
	void CalculateReward();
	void UpdateQ(float reward);
	void ExecuteAction();
	void UpdateState();

	// Regular Functions
	void WalkLeft();
	void WalkRight();
	void Attack();
	void FaceNearestPlayer();

	float chooseActionTimeoutTimer;
	float stateUpdateTimer;
	float speed;
	float newX;
	float Q_EstimatedOptimalFutureValue;
	float Q_DiscountFactor;
	float Q_LearningRate;
	State3 currentState;
	Action currentAction;
	TArray<TArray<float, TFixedAllocator<5>>, TFixedAllocator<5>> AI_Q;

	UPROPERTY(EditAnywhere)
		bool inCombat;

	UPROPERTY(EditAnywhere)
		int difficulty;

	// Animations
	UPROPERTY(EditAnywhere)
		UPaperFlipbook* idle;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* walk;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* attack;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* dead;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* jumpAnim;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* hurtAnim;

	// Particles
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* muzzleFlashParticle;

protected:
	UFUNCTION(BlueprintCallable)
		void EndAttack();

	UFUNCTION(BlueprintCallable)
		static void WriteStringToFile(FString FilePath, FString String);

	// Called when landed
	virtual void Landed(const FHitResult& Hit) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		ABoomBoom* boomBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere)
		AActor* playerToAttack;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> bulletClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<class AComicFX> comicFX;
};