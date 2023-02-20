// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ZipZap.generated.h"

/**
 * 
 */

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
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UPaperFlipbook* jumping;

	UFUNCTION(BlueprintCallable)
	void UpdateAnimation();
	UFUNCTION(BlueprintCallable)
	void UpdateRotation();
	UFUNCTION(BlueprintCallable)
	void move(float scaleVal);
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABoomBoom* boomBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputComponent* Input;
};
