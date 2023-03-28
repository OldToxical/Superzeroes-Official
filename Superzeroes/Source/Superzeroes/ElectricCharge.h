// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ElectricCharge.generated.h"

/**
 *
 */
UCLASS()
class SUPERZEROES_API AElectricCharge : public AProjectile
{
	GENERATED_BODY()

private:
	AElectricCharge();

	virtual void BeginPlay() override;

	UFUNCTION()
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION()
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	// Particles
	UPROPERTY(EditAnywhere)
		UParticleSystem* boomBoomImpact;
	UPROPERTY(EditAnywhere)
		UParticleSystem* zipZapImpact;

	FVector startPos;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<class AComicFX> comicFX;
};