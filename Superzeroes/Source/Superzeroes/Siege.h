// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Enemy.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Siege.generated.h"

#define SiegeModeExecutionLength 10.2
#define InputTime 1.3
#define ShootCooldownTime 2
#define MaximumXDistanceBetweenPlayersForInitiatingSiegeMode 120
#define MaximumZDistanceBetweenPlayersForInitiatingSiegeMode 40
#define InitiationAnimationLength 2.2

UENUM()
enum class SiegeState : uint8
{
	Idle,
	Walking,
	Attacking
};

class ABoomBoom;
class AZipZap;
class AProjectile;

UCLASS()
class SUPERZEROES_API ASiege : public APaperCharacter
{
	GENERATED_BODY()

public:
	ASiege();
	~ASiege();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void SetupBoomBoomInputComponent(UInputComponent* bbInput);
	void SetupZipZapInputComponent(UInputComponent* zzInput);

protected:
	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);

	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	UFUNCTION(BlueprintCallable)
		void EndAttackAnimation();

	void ExecuteSiegeMode();
	void UpdateAnimation();
	void HandleBoomBoomInput(float scaleVal);
	UFUNCTION(BlueprintCallable)
	void HandleZipZapInput(float scaleVal);
	void Move(float scaleVal);
	UFUNCTION(BlueprintCallable)
	void Shoot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		SiegeState state;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCharacterMovementComponent* charMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* flipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* walk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABoomBoom* boomBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> electricChargeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* muzzleFlash;

	UPROPERTY(BlueprintReadWrite)
		UNiagaraComponent* smokeParticle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UUserWidget* initiationAnimationUserWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool modeIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int bullets;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool shotFired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool stepMade;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool inputAvailable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float boomBoomInputTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float zipZapInputTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float executionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float inititationAnimationTimer;

	//Audio variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* siegeActivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* siegeVoice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* siegeShoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
		class USoundBase* siegeWalk;

	// Blueprint references
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UCameraShakeBase> cameraShakeLandBP;
};
