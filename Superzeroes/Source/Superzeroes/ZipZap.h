// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ZipZap.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class State2 : uint8
{
	Idle ,
	Running,
	Jumping,
	Attacking,
	Charge_Attacking,
	Combo_Savage,
	Combo_2
};
class ABoomBoom;

UCLASS()
class SUPERZEROES_API AZipZap : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZipZap();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
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
		class UPaperFlipbook* strongAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* strongAttackCharge;

	UFUNCTION(BlueprintCallable)
	void UpdateAnimation();
	UFUNCTION(BlueprintCallable)
		void UpdateState();
	UFUNCTION(BlueprintCallable)
		void UpdateComboAttack_Savage();
	UFUNCTION(BlueprintCallable)
	void move(float scaleVal);
	UFUNCTION(BlueprintCallable)
		void Attack(float scaleVal);
	UFUNCTION(BlueprintCallable)
		void EndAttack();
	UFUNCTION(BlueprintCallable)
	void InitiateComboAttack_Savage();

	void SetBoomBoomReference(ABoomBoom* boomBoom_) { boomBoom = boomBoom_; }
	UFUNCTION(BlueprintCallable)
	void SetupPlayerInput(UInputComponent* input_);

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
	
	// Variable to keep track of how long the "Attack" buton is being held down
	UPROPERTY(EditAnywhere)
		float attackInputTimer;

	// Variable for the character's speed
	UPROPERTY(EditAnywhere)
		float characterSpeed;
	// Variable to keep track of how long the savage attack is to be executed
	UPROPERTY(EditAnywhere)
		float ComboAttack_Savage_ExecutionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;
};
