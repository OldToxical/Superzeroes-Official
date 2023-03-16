// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Bullet.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ABullet : public AProjectile
{
	GENERATED_BODY()

private:
	ABullet();

	virtual void BeginPlay() override;
	void CalculateDamage();

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
};
