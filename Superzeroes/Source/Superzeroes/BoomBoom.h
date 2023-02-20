// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ZipZap.h"
#include "BoomBoom.generated.h"

#define SavageComboExecutionTime 10
#define StrongAttackMinimumInputTime 0.5

UENUM()
enum class State
{
	Idle,
	Running,
	Jumping,
	Attacking,
	Combo_Savage,
	Combo_2
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
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UCharacterMovementComponent* charMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* flipbook;

	// Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* idle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* run;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UPaperFlipbook* jumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* simpleAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* strongAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbook* strongAttackCharge;

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
	void Attack(float scaleVal);
	UFUNCTION(BlueprintCallable)
	void EndAttack();
	UFUNCTION(BlueprintCallable)
	void InitiateComboAttack_Savage(float directionRotation);

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

	// Variable for the character's speed
	UPROPERTY(EditAnywhere)
		float characterSpeed;

	// Variable to keep track of how long the "Attack" buton is being held down
	UPROPERTY(EditAnywhere)
		float attackInputTimer;

	// Variable to keep track of how long the savage attack is to be executed
	UPROPERTY(EditAnywhere)
		float ComboAttack_Savage_ExecutionTimer;
};
