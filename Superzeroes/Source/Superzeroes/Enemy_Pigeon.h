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
<<<<<<< Updated upstream
	RunningAway
=======
	Dead
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	class UBoxComponent* hitbox;
	class UBoxComponent* collision;
	TArray<TArray<float, TFixedAllocator<6>>, TFixedAllocator<6>> AI_Q;
=======
	TArray<TArray<float, TFixedAllocator<5>>, TFixedAllocator<5>> AI_Q;
>>>>>>> Stashed changes

	UPROPERTY(EditAnywhere)
	    bool inCombat;

	// Animations
	UPROPERTY(EditAnywhere)
	    UPaperFlipbook* idle;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* walk;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* attack;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* jumpAnim;

	// Particles
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* muzzleFlashParticle;

protected:
	UFUNCTION(BlueprintCallable)
		void ProcessBulletCollision(FVector hitPos);

	UFUNCTION(BlueprintCallable)
	    void EndAttack();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	    ABoomBoom* boomBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	    AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere)
		AActor* playerToAttack;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> bulletClass;
};
