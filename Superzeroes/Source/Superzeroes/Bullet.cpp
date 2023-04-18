// Fill out your copyright notice in the Description page of Project Settings.
#include "Bullet.h"
#include "BoxTrigger.h"
#include "Enemy.h"
#include "Siege.h"
#include "ComicFX.h"

ABullet::ABullet()
{
	damage = 10.f;
	startPos = FVector(0.f, 0.f, 0.f);
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();

	collider->OnComponentBeginOverlap.AddDynamic(this, &ABullet::overlapBegin);
	collider->OnComponentEndOverlap.AddDynamic(this, &ABullet::overlapEnd);
	collider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	startPos = GetActorLocation();
}

void ABullet::CalculateDamage()
{
	FVector collidingPoint = GetActorLocation();
	FVector distanceTravelled = FVector(abs(startPos.X - collidingPoint.X), abs(startPos.Y - collidingPoint.Y), abs(startPos.Z - collidingPoint.Z));
	float distance = sqrt(pow(distanceTravelled.X, 2) + pow(distanceTravelled.Z, 2));

	if (distance <= 200.f)
	{
		damage = 30.f;
		return;
	}
	else if (distance >= 800.f)
	{
		damage = 15.f;
		return;
	}

	damage = abs(((800.f - distance) / 800.f) * 30.f);
}

void ABullet::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(ABoomBoom::StaticClass()))
		{
			if (ABoomBoom* boomBoom = Cast<ABoomBoom>(otherActor))
			{
				if (boomBoom->GetState() != State::Dead)
				{
					CalculateDamage();
					boomBoom->setHealth(boomBoom->getHealth() - damage);
					FVector impactSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 30.f, GetActorLocation().Z);
					UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, impactSpawnLocation, FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
				}
				else
				{
					return;
				}
			}
		}

		if (otherActor->IsA(AZipZap::StaticClass()))
		{
			if (AZipZap* zipZap = Cast<AZipZap>(otherActor))
			{
				if (zipZap->GetState() != State2::Dead)
				{
					CalculateDamage();
					zipZap->setHealth(zipZap->getHealth() - damage);
					FVector impactSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 30.f, GetActorLocation().Z);
					UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), zipZapImpact, impactSpawnLocation, FRotator(0, 0, 0), FVector(.6f, .6f, .6f));
					FVector location = zipZap->GetActorLocation();
					location.Z += 30.f;
					location.Y -= 0.1f;
					AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, location, GetActorRotation());
					cfx->spriteChanger(1);
				}
				else
				{
					return;
				}
			}
		}

		if (otherActor->IsA(ASiege::StaticClass()))
		{
			FVector impactSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 30.f, GetActorLocation().Z);
			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, impactSpawnLocation, FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
		}

		if (!otherActor->IsA(ABoxTrigger::StaticClass()) && !otherActor->IsA(AEnemy::StaticClass()))
		{
			FVector impactDebrisSpawnLocation = FVector(GetActorLocation().X, 1.f, GetActorLocation().Z);
			UParticleSystemComponent* impactDebris = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), impactParticle, impactDebrisSpawnLocation, FRotator(0.f, 0.f, 0.f), FVector(.5f, .5f, .5f));
			Destroy();
		}
	}
}

void ABullet::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}