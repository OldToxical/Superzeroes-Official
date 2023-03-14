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

#define SavageComboExecutionTime 10
#define StrongAttackMinimumInputTime 0.5
#define SimpleAttackSequenceTimeout 0.6
#define SimpleAttackAnimationLength 0.27
#define MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack 60
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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
		float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
		void setHealth(float newHealth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Rotator variable for the flipbook's rotation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	// Enum instance for the character's state
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		State characterState;

	// Reference to Zip Zap's object
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

	// Reference to Siege's object
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ASiege* siegeMode;

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

	//Variable to keep track of Boom Boom's health
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health;

	// Particles' variables
	UPROPERTY(BlueprintReadWrite)
		UParticleSystemComponent* smokeParticle;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		//class UBoxComponent* collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool toxicDamage;

	float healTimer;
	float deathTimer;
	int currentLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FVector> spawnLoc;
};