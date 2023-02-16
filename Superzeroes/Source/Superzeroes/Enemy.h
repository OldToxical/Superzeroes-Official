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

	// Animation states
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* idle;

	UFUNCTION(BlueprintCallable)
		void UpdateAnimation();

	UFUNCTION(BlueprintCallable)
		void UpdateRotation();

	UFUNCTION(BlueprintCallable)
		void moveLeft(float scaleVal);

	UFUNCTION(BlueprintCallable)
		void moveRight(float scaleVal);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;
};
