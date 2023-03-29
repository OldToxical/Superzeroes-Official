// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "ZipZap.generated.h"

#define MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack 120

UENUM(BlueprintType)
enum class State2 : uint8
{
	Idle,
	Running,
	Jumping,
	Attacking,
	Combo_Projectile,
	Hurt,
	Siege,
	Dead
};

class ABoomBoom;
class AEnemy;
class AProjectile;

UCLASS()
class SUPERZEROES_API AZipZap : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZipZap();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCharacterMovementComponent* charMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbookComponent* flipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* idle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* run;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* jumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* simpleAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* initiateBoomBoomSavageComboAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* projectileFly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* projectileFlyElectrified;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* hurt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* dead;

	UFUNCTION(BlueprintCallable)
		void UpdateAnimation();
	UFUNCTION(BlueprintCallable)
		void UpdateState();
	UFUNCTION(BlueprintCallable)
		void move(float scaleVal);
	UFUNCTION(BlueprintCallable)
		void ExecuteJump();
	UFUNCTION(BlueprintCallable)
		void climb(float scaleVal);
	UFUNCTION(BlueprintCallable)

		void EndAttack();
	UFUNCTION(BlueprintCallable)
		void InitiateComboAttack_Savage();
	UFUNCTION(BlueprintCallable)
		void InitiateComboAttack_Projectile(float directionRotation);
	UFUNCTION(BlueprintCallable)
		void Electrify();
	UFUNCTION(BlueprintCallable)
		bool IsFacingBoomBoom();
	UFUNCTION(BlueprintCallable)
		void SetBoomBoomReference(ABoomBoom* boomBoom_) { boomBoom = boomBoom_; }
	UFUNCTION(BlueprintCallable)
		void SetupPlayerInput(UInputComponent* input_);
	UFUNCTION(BlueprintCallable)
		void ProcessShoot(float damage_);
	UFUNCTION(BlueprintCallable)
		void SetLevelIndex(int level) { currentLevel = level; }
	UFUNCTION(BlueprintCallable)
		void Shoot();
	UFUNCTION(BlueprintCallable)
		void SetState(State2 state_) { characterState = state_; }
	UFUNCTION(BlueprintCallable)
		void SetInputAvailability(bool isAvailable) { inputAvailable = isAvailable; }

	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	// Getters and setters
	UFUNCTION(BlueprintCallable)
		float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
		void setHealth(float newHealth);
	UFUNCTION(BlueprintCallable)
		State2 GetState() { return characterState; }
	UFUNCTION(BlueprintCallable)
		float getMeter() { return meter; };
	UFUNCTION(BlueprintCallable)
		void setMeter(float newMeter) { meter += newMeter; if (meter > 100.f) { meter = 100.f; } };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when landed
	virtual void Landed(const FHitResult& Hit) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;
	// Enum instance for the character's state
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		State2 characterState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABoomBoom* boomBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputComponent* Input;

	// Variable for the character's speed
	UPROPERTY(EditAnywhere)
		float characterSpeed;

	// Variable to keep track of what time should pass to execute the jump
	UPROPERTY(EditAnywhere)
		float jumpPreludeTimer;

	// Variable to keep track of what time should pass to start following whether zip zap is falling when he's in projectile attack state
	UPROPERTY(EditAnywhere)
		float projectileAttackResetStateTimeoutTimer;

	// Variable to keep track whether zip zap is electrified while he's executing his projectile combo attack
	UPROPERTY(EditAnywhere)
		bool isElectrified;

	// Variable to keep track whether zip zap is shooting or not during the current attack stage
	UPROPERTY(EditAnywhere)
		bool isShooting;

	// Variable to keep track whether zip zap has dealt damage
	UPROPERTY(EditAnywhere)
		bool damageDealt;

	// Variable to keep track whether the input is available, depending on whether siege mode is being activated at the moment
	UPROPERTY(EditAnywhere)
		bool inputAvailable;

	// Variable to keep track whether zip zap has iniated savage combo attack
	UPROPERTY(EditAnywhere)
		bool savageInitiated;

	//Variable to keep track of Zip Zap's health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float health;

	//Variable to keep track of Zip Zap's special meter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float meter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float refillTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float skillCost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool toxicDamage;

	float healTimer;
	float deathTimer;
	int currentLevel;
	bool canClimb;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FVector> spawnLoc;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> electricChargeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<class AComicFX> zap;

	// Particles
	UPROPERTY(EditAnywhere)
		UParticleSystem* muzzleFlashParticle;
};