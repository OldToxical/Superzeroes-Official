// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "ZipZap.h"
#include "Siege.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraSystemWidget.h"
#include "BoomBoom.generated.h"

#define SavageComboExecutionTime 3
#define StrongAttackMinimumInputTime 0.5
#define SimpleAttackSequenceTimeout 0.65
#define SimpleAttackAnimationLength 0.38
#define AcutalPunchDelay 0.2

UENUM()
enum class BB_State : uint8
{
	Idle,
	Running,
	Jumping,
	Attacking,
	Combo_Savage,
	Hurt,
	Siege,
	Dead
};

UCLASS()
class SUPERZEROES_API ABoomBoom : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoomBoom();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Variable for the character movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCharacterMovementComponent* charMove;

	// Variable for the flipbook component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* flipbook;

	// Flipbook Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* idle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* run;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* jumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* simpleAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* simpleAttackSequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* strongAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* strongAttackCharge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* savageComboAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* hurt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* dead;

	// Functions for movement management (animations and motion)
	UFUNCTION(BlueprintCallable)
	void UpdateAnimation();
	UFUNCTION(BlueprintCallable)
	void UpdateState();
	UFUNCTION(BlueprintCallable)
	void UpdateComboAttack_Savage();
	UFUNCTION(BlueprintCallable)
	void move(float scaleVal);
	UFUNCTION(BlueprintCallable)
	void ExecuteJump();
	UFUNCTION(BlueprintCallable)
	void climb(float scaleVal);

	// Functions for combat functionalities
	UFUNCTION(BlueprintCallable)
	void Attack(float scaleVal);
	UFUNCTION(BlueprintCallable)
	void EndAttack();
	UFUNCTION(BlueprintCallable)
	void InitiateComboAttack_Savage(float directionRotation);
	UFUNCTION(BlueprintCallable)
	void InitiateZipZapComboAttack_Projectile();
	UFUNCTION(BlueprintCallable)
	bool IsFacingZipZap();
	UFUNCTION(BlueprintCallable)
	void ProcessHit(float damage_);

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
	BB_State GetState() { return characterState; }
	UFUNCTION(BlueprintCallable)
	float getMeter() { return meter; };
	UFUNCTION(BlueprintCallable)
	void setMeter(float newMeter) { meter += newMeter; if (meter > 100.f) { meter = 100.f; } if (meter < 0.0f) { meter = 0.0f; } };
	UFUNCTION(BlueprintCallable)
	void SetLevelIndex(int level) { currentLevel = level; }
	UFUNCTION(BlueprintCallable)
	void SetState(BB_State state_) { characterState = state_; }
	UFUNCTION(BlueprintCallable)
	void SetInputAvailability(bool isAvailable) { inputAvailable = isAvailable; }
	UFUNCTION(BlueprintCallable)
	void SetZipZapReference(AZipZap* zipZap_) { zipZap = zipZap_; };
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when landed
	virtual void Landed(const FHitResult& Hit) override;

	// Rotator variable for the flipbook's rotation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FRotator rotation;

	// Enum instance for the character's state
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	BB_State characterState;

	// Reference to Zip Zap's object
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AZipZap* zipZap;

	// Variable for the character's speed
	UPROPERTY(EditAnywhere)
	float characterSpeed;

	// Variable for the maximum distance (for X and Z) that the two characters should be from each other so that projectile combo can be activated
	UPROPERTY(EditAnywhere)
	float MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack = 150.f;

	// Variable to keep track of how long the "Attack" buton is being held down
	UPROPERTY(EditAnywhere)
	float attackInputTimer;

	// Variable to keep track of how long the savage attack is to be executed
	UPROPERTY(EditAnywhere)
	float ComboAttack_Savage_ExecutionTimer;

	// Variable to keep track of what time should pass to execute sequence of simple attack
	UPROPERTY(EditAnywhere)
	float simpleAttack_sequenceTimeoutTimer;

	// Variable to keep track of what time should pass to execute the jump
	UPROPERTY(EditAnywhere)
	float jumpPreludeTimer;

	// Variable to keep track of what time should pass to execute the impact of the punch
	UPROPERTY(EditAnywhere)
	float punchPreludeTimer;

	// Variable to keep track whether the simple attack was sequenced
	UPROPERTY(EditAnywhere)
	bool isSimpleAttackSequenced;

	// Variable to keep track whether the punch will result in launching zip zap or applying damage to an enemy
	UPROPERTY(EditAnywhere)
	bool launchZipZap;

	// Variable to keep track whether the input is available, depending on whether siege mode is being activated at the moment
	UPROPERTY(EditAnywhere)
	bool inputAvailable;

	//Variable to keep track of Boom Boom's health
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	// Variables to keep track of Boom Boom's special meter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float meter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float refillTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
	float skillCost;

	// Particles' variables
	UPROPERTY(BlueprintReadWrite)
	UNiagaraComponent* smokeParticle;

	UPROPERTY(EditAnywhere)
	UParticleSystem* zipZapImpact;

	UPROPERTY(EditAnywhere)
	UParticleSystem* enemyImpact;

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

	// Variable to keep track of whether or not healing is currently active
	bool healing;

	// Variable to keep track of when UI particle is active
	bool isUIparticleActive;

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

	// Variable to keep track of whether or not spawning of Zip-Zap should happen or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canSpawnZipZap;

	//Audio variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jumpSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jump2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jump3SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* jump4SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* landSFX;

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
	class USoundBase* growlSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* growl2SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* growl3SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* growl4SFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* deathSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* attackSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* hurtSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* healthRecharge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* meterFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* glassBreak;

	// Array of locations, which serve as a starting point in each level; used in respawning
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FVector> spawnLoc;

	// Variable for the comic effects' blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
	TSubclassOf<class AComicFX> comicFX;

	// Variables for camera shake functionality
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UCameraShakeBase> cameraShakeLandBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UCameraShakeBase> cameraShakeHitBP;
};