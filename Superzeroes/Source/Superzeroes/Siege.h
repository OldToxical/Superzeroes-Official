// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Enemy.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Siege.generated.h"

#define SiegeModeExecutionLength 10
#define InputTime 3
#define ShootCooldownTime 0.5
#define MaximumXDistanceBetweenPlayersForInitiatingSiegeMode 60
#define MaximumZDistanceBetweenPlayersForInitiatingSiegeMode 20

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
	void SetupPlayerInput(UInputComponent* input_);

protected:
	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);

	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	UFUNCTION(BlueprintCallable)
		void EndAttackAnimation();

	void HandleBoomBoomInput(float scaleVal);
	void HandleZipZapInput(float scaleVal);
	void ExecuteSiegeMode();
	void Move(float scaleVal);
	void Shoot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCharacterMovementComponent* charMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* flipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* intro;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputComponent* Input;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> electricChargeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UNiagaraSystem* electricBeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* muzzleFlash;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool modeIsActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool shotFired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float boomBoomInputTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float zipZapInputTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float executionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float shootCooldownTimer;
};
