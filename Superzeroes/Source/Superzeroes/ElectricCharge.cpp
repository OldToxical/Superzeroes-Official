// Fill out your copyright notice in the Description page of Project Settings.
#include "ElectricCharge.h"
#include "BoxTrigger.h"

AElectricCharge::AElectricCharge()
{
	damage = 0.f;
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

void AElectricCharge::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
			{
				Enemy->TakeEnemyDamage(damage);
			}
		}

		if (!otherActor->IsA(ABoxTrigger::StaticClass()) && !otherActor->IsA(ABoomBoom::StaticClass()) && !otherActor->IsA(AZipZap::StaticClass()))
		{
			Destroy();
		}
	}
}

void AElectricCharge::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}