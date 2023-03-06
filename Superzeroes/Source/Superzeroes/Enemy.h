// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API AEnemy : public APaperCharacter
{
protected:
	GENERATED_BODY()
	AEnemy();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void AI();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCharacterMovementComponent* characterMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* flipbookComponent;

	UFUNCTION(BlueprintCallable)
		void UpdateAnimation();

	UFUNCTION(BlueprintCallable)
		void UpdateRotation();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	UPROPERTY(VisibleAnywhere)
		float healthPoints;

	UPROPERTY(VisibleAnywhere)
		float damage;

	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> actorsToIgnore;

public:
	void TakeEnemyDamage(float damage_) { healthPoints -= damage_; }
	void AddToGetActorsToIgnore(AActor* actor) { actorsToIgnore.Add(actor); }
};
