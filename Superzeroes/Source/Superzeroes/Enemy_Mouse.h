// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Enemy_Mouse.generated.h"

#define Q_LearningRate 0.9
#define Q_DiscountFactor 0.55
#define Q_EstimatedOptimalFutureValue 20
#define MinimumDistanceToGetIntoCombatX 100
#define MinimumDistanceToGetIntoCombatZ 50
#define MinimumDistanceToDealDamage 50

class ABoomBoom;
class AZipZap;

enum State3
{
	Idle,
	Jumping,
	WalkingLeft,
	WalkingRight,
	Attacking
};

enum Action
{
	GoIdle,
	Jump,
	WalkLeft,
	WalkRight,
};

UCLASS()
class SUPERZEROES_API AEnemy_Mouse : public AEnemy
{
	GENERATED_BODY()

private:
	AEnemy_Mouse();

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
	void RunAway();
	void GoToPlayer();
	void DealDamage();

	float chooseActionTimeoutTimer;
	float stateUpdateTimer;
	float speed;
	float newX;
	State3 currentState;
	Action currentAction;
	class UBoxComponent* collision;
	TArray<TArray<float, TFixedAllocator<4>>, TFixedAllocator<4>> AI_Q;

	UPROPERTY(EditAnywhere)
	    bool inCombat;

	bool hitAvailable;

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
		UParticleSystem* boomBoomImpact;

protected:
	UFUNCTION(BlueprintCallable)
	    void EndAttack();

	UPROPERTY(BlueprintReadWrite)
	    ABoomBoom* boomBoom;

	UPROPERTY(BlueprintReadWrite)
	    AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere)
		AActor* playerToAttack;
};