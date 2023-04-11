// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "ZipZap.h"
#include "Siege.h"
#include "Particles/ParticleSystemComponent.h"
#include "BoomBoom.generated.h"

#define SavageComboExecutionTime 3
#define StrongAttackMinimumInputTime 0.5
#define SimpleAttackSequenceTimeout 0.6
#define SimpleAttackAnimationLength 0.27
#define MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack 120
#define AcutalPunchDelay 0.2

UENUM()
enum class State : uint8
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
	~ABoomBoom();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCharacterMovementComponent* charMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbookComponent* flipbook;

	// Animations
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
		class UPaperFlipbook* hurt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* dead;

	// Functions
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
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);
	UFUNCTION(BlueprintCallable)
		void ProcessHit(float damage_);
	UFUNCTION(BlueprintCallable)
		void SetLevelIndex(int level) { currentLevel = level; }
	UFUNCTION(BlueprintCallable)
		void SetState(State state_) { characterState = state_; }
	UFUNCTION(BlueprintCallable)
		void SetInputAvailability(bool isAvailable) { inputAvailable = isAvailable; }
	UFUNCTION(BlueprintCallable)
		void SetZipZapReference(AZipZap* zipZap_) { zipZap = zipZap_; };
	UFUNCTION(BlueprintCallable)
		void WriteFile(FString text);

	// Setters and getters
	UFUNCTION(BlueprintCallable)
		float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
		void setHealth(float newHealth);
	UFUNCTION(BlueprintCallable)
	    State GetState() { return characterState; }
	UFUNCTION(BlueprintCallable)
		float getMeter() { return meter; };
	UFUNCTION(BlueprintCallable)
		void setMeter(float newMeter) { meter += newMeter; if (meter > 100.f) { meter = 100.f; } if (meter < 0.0f) { meter = 0.0f; } };

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
		State characterState;

	// Reference to Zip Zap's object
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

	// Variable for the character's speed
	UPROPERTY(EditAnywhere)
		float characterSpeed;

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

	//Variable to keep track of Boom Boom's special meter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float meter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float refillTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combo_Meter)
		float skillCost;

	// Particles' variables
	UPROPERTY(BlueprintReadWrite)
		UParticleSystemComponent* smokeParticle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool toxicDamage;

	//used for changing between the two toxic walk sound sfx
	bool toxicWalkSoundBool;
	float healTimer;
	bool healing;
	float deathTimer;
	float walkSoundTimer;
	//Values for respawn timer and heal timer that can be changed in blueprint, so it can be tested without compiling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
		float respawnTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
		float timeToHeal;
	//This is so that the walk sound effect doesn't play every single frame
	//there may be a better way of doing this?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
		float TimeBetweenWalkSounds;

	int currentLevel;
	bool canClimb;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canSpawnZipZap;

	//Audio variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* jumpSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* landSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* walkSFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* toxicWalk1SFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* toxicWalk2SFX;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FVector> spawnLoc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<class AComicFX> comicFX;
};