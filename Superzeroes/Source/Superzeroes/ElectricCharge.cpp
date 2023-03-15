// Fill out your copyright notice in the Description page of Project Settings.
#include "ElectricCharge.h"
#include "BoxTrigger.h"

AElectricCharge::AElectricCharge()
{
	damage = 10.f;
	startPos = FVector(0.f, 0.f, 0.f);
}

void AElectricCharge::BeginPlay()
{
	Super::BeginPlay();

	collider->OnComponentBeginOverlap.AddDynamic(this, &AElectricCharge::overlapBegin);
	collider->OnComponentEndOverlap.AddDynamic(this, &AElectricCharge::overlapEnd);
	collider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	startPos = GetActorLocation();
}

void AElectricCharge::CalculateDamage()
{
	FVector collidingPoint = GetActorLocation();
	FVector distanceTravelled = FVector(abs(startPos.X - collidingPoint.X), abs(startPos.Y - collidingPoint.Y), abs(startPos.Z - collidingPoint.Z));
	float distance = sqrt(pow(distanceTravelled.X, 2) + pow(distanceTravelled.Z, 2));
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::White, FString::SanitizeFloat(distance));

	if (distance <= 50.f)
	{
		damage = 15.f;
		return;
	}
	else if (distance >= 100.f)
	{
		damage = 30.f;
		return;
	}

	damage = abs(((100.f - distance) / 100.f) * 30.f);
}

void AElectricCharge::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
			{
				Enemy->TakeEnemyDamage(20.f);
			}
		}

		if (!otherActor->IsA(ABoxTrigger::StaticClass()))
		{
			Destroy();
		}
	}
	
}

void AElectricCharge::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}