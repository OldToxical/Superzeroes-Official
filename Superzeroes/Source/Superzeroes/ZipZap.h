// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ZipZap.generated.h"

#define MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack 60

/**
 *
 */
UENUM(BlueprintType)
enum class State2 : uint8
{
	Idle,
	Running,
	Jumping,
	Attacking,
	Combo_Projectile,
	Hurt,
	Dead
};
class ABoomBoom;
class AEnemy;

UCLASS()
class SUPERZEROES_API AZipZap : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZipZap();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
		void Attack();
	UFUNCTION(BlueprintCallable)
		void EndAttack();
	UFUNCTION(BlueprintCallable)
		void InitiateComboAttack_Savage();
	UFUNCTION(BlueprintCallable)
		void InitiateComboAttack_Projectile(float directionRotation);
	UFUNCTION(BlueprintCallable)
		void UpdateComboAttack_Projectile();
	UFUNCTION(BlueprintCallable)
		void Electrify();
	//UFUNCTION(BlueprintCallable)
		//void HitCheck();
	UFUNCTION(BlueprintCallable)
		void StopProjectileAttack();
	UFUNCTION(BlueprintCallable)
		bool IsFacingBoomBoom();
	UFUNCTION(BlueprintCallable)
		void SetBoomBoomReference(ABoomBoom* boomBoom_) { boomBoom = boomBoom_; }
	UFUNCTION(BlueprintCallable)
		void SetupPlayerInput(UInputComponent* input_);
	UFUNCTION(BlueprintCallable)
		void ProcessHit(float damage_);

	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);


	UFUNCTION(BlueprintCallable)
		float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
		void setHealth(float newHealth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	//Variable to keep track of Zip Zap's health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool toxicDamage;

	float healTimer;
	float deathTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector spawnLoc;
};