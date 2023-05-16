// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystemWidget.h"
#include "ZipZap.generated.h"

#define MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack 150

UENUM(BlueprintType)
enum class ZZ_State : uint8
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

	// Variable for the character movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCharacterMovementComponent* charMove;

	// Variable for the flipbook component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* flipbook;

	// Flipbook animations
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
	class UPaperFlipbook* hurt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* dead;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* airAttack;

	// Functions for movement management (animations and motion)
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

	// Functions for combat functionalities
	UFUNCTION(BlueprintCallable)
	void InitiateComboAttack_Savage();
	UFUNCTION(BlueprintCallable)
	void InitiateComboAttack_Projectile(float directionRotation);
	UFUNCTION(BlueprintCallable)
	bool IsFacingBoomBoom();
	UFUNCTION(BlueprintCallable)
	void ProcessShoot(float damage_, bool inAir);
	UFUNCTION(BlueprintCallable)
	void Shoot();

	// Collision functions for delegates
	UFUNCTION(BlueprintCallable)
	void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
	void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	// Getters and setters
	UFUNCTION(BlueprintCallable)
	float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
	void setHealth(float newHealth);
	UFUNCTION(BlueprintCallable)
	ZZ_State GetState() { return characterState; }
	UFUNCTION(BlueprintCallable)
	float getMeter() { return meter; };
	UFUNCTION(BlueprintCallable)
	void setMeter(float newMeter) { meter += newMeter; if (meter > 100.f) { meter = 100.f; } if (meter < 0.0f) { meter = 0.0f; } };
	UFUNCTION(BlueprintCallable)
	void SetLevelIndex(int level) { currentLevel = level; }
	UFUNCTION(BlueprintCallable)
	void SetState(ZZ_State state_) { characterState = state_; }
	UFUNCTION(BlueprintCallable)
	void SetInputAvailability(bool isAvailable) { inputAvailable = isAvailable; }
	UFUNCTION(BlueprintCallable)
	void Respawn() { SetActorLocation(spawnLoc[currentLevel]); }
	UFUNCTION(BlueprintCallable)
	void EnableLevelFinishedParticle() { levelFinishedParticle->ActivateSystem(false); }
	UFUNCTION(BlueprintCallable)
	void DisableLevelFinishedParticle() { levelFinishedParticle->DeactivateSystem(); }
	UFUNCTION(BlueprintCallable)
	void EnableSiegeInitiationParticle() { if (!siegeInitiationParticle->IsActive() && IsValid(siegeInitiationParticle)) { siegeInitiationParticle->ActivateSystem(); } }
	UFUNCTION(BlueprintCallable)
	void DisableSiegeInitiationParticle() { if (IsValid(siegeInitiationParticle)) { siegeInitiationParticle->DeactivateSystem(); } }
	UFUNCTION(BlueprintCallable)
	bool IsOnLadder() { return canClimb; }

	UInputComponent* GetInputComponent() { return InputComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when landed
	virtual void Landed(const FHitResult& Hit) override;

	// Called when Pawn is possessed
	UFUNCTION(BlueprintCallable)
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// Variable for the rotator that keeps track of the rotation of the flipbook component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FRotator rotation;

	// Enum instance for the character's state
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ZZ_State characterState;

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

	//Variables to keep track of Zip Zap's special meter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float meter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float refillTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float skillCost;

	// Particles' variables
	UPROPERTY(BlueprintReadWrite)
	UNiagaraComponent* smokeParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* boomBoomImpact;

	UPROPERTY(EditAnywhere)
	UParticleSystem* enemyImpact;

	UPROPERTY(EditAnywhere)
	UParticleSystem* muzzleFlashParticle;

	UPROPERTY(BlueprintReadWrite)
	UParticleSystemComponent* siegeInitiationParticle;

	UPROPERTY(BlueprintReadWrite)
	UNiagaraSystemWidget* comboBarParticle;

	UPROPERTY(BlueprintReadWrite)
	UNiagaraSystemWidget* healthBarParticle;

	UPROPERTY(BlueprintReadWrite)
	UNiagaraSystemWidget* levelFinishedParticle;

	 // Indicated whether or not a toxic damage sound should be played or not
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool toxicDamage;

	// Used for changing between the two toxic walk sound sfx
	bool toxicWalkSoundBool;

	// Variable to keep track of when UI combo particle is active
	bool isComboParticleActive;

	// Variable to keep track of whether the character is colliding with a next level trigger
	bool isSpawningProjectileAvailable;

	// Timers for health management
	float healTimer;
	float deathTimer;

	// Values for respawn timer and heal timer that can be changed in blueprint, so it can be tested without compiling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
	float respawnTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
	float timeToHeal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
	float healRate;

	// Variable for keeping track of what level the characters is currently on
	int currentLevel;

	// Variable for keeping track whether or not the character is on a ladder
	bool canClimb;

	// Variable to keep track of whether or not a step has been made while walking; used for sound initiation
	bool stepMade;

	// Variable to keep track of whether or not healing is currently active
	bool healing;

	//Audio variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jumpSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jump2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jump3SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* landSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* land2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* land3SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* land4SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* walkSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* walk2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* walk3SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* walk4SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* toxicWalk1SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* toxicWalk2SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* death1SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* death2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* death3SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* hurtSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* healthRecharge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* meterFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* flyingSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* attackSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* hitSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class UAudioComponent* audComp;

	// Array of locations, which serve as a starting point in each level; used in respawning
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FVector> spawnLoc;

	// Variable for the projectile that will be spawned on shooting
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectile> electricChargeClass;

	// Variable of the siege mode blueprint
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ASiege> siegeBPClass;

	// Variable for the comic effects' blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
	TSubclassOf<class AComicFX> zap;
};