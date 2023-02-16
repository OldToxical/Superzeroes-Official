// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ZipZap.h"
#include "BoomBoom.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ABoomBoom : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoomBoom();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AZipZap* zipZap;

private:
	// Functions for controlling Zip Zap
	void moveZipZap(float scaleVal);
};
