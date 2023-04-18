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
#define Q_DiscountFactor 0.2
#define Q_EstimatedOptimalFutureValue 15
#define MinimumDistanceToGetIntoCombatX 500
#define MinimumDistanceToGetIntoCombatZ 50
#define MinimumDistanceToDealDamage 100

class ABoomBoom;
class AZipZap;

enum State4
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
	WalkRight
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
	void GoToPlayer();
	void DealDamage();

	UFUNCTION()
		void OverlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);

	UFUNCTION()
		void OverlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);

	float chooseActionTimeoutTimer;
	float stateUpdateTimer;
	float speed;
	float newX;
	State4 currentState;
	Action currentAction;
	TArray<TArray<float, TFixedAllocator<4>>, TFixedAllocator<4>> AI_Q;

	UPROPERTY(EditAnywhere)
	    bool inCombat;

	bool hitAvailable;
	bool deathFXcompleted;
	bool isColliding;

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
		UParticleSystem* boomBoomImpact;

	UPROPERTY(EditAnywhere)
		UParticleSystem* zipZapImpact;

protected:
	UFUNCTION(BlueprintCallable)
	    void EndAttack();

	// Called when landed
	virtual void Landed(const FHitResult& Hit) override;

	UPROPERTY(BlueprintReadWrite)
	    ABoomBoom* boomBoom;

	UPROPERTY(BlueprintReadWrite)
	    AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere)
		AActor* playerToAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<class AComicFX> comicFX;

	//Audio variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack1SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack3SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack4SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack5SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		USoundBase* attack6SFX;
};