// Fill out your copyright notice in the Description page of Project Settings.
#include "Bullet.h"
#include "BoxTrigger.h"
#include "ComicFX.h"

ABullet::ABullet()
{
	damage = 0.f;
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
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::White, FString::SanitizeFloat(damage));

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

void ABullet::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(ABoomBoom::StaticClass()))
		{
			if (ABoomBoom* boomBoom = Cast<ABoomBoom>(otherActor))
			{
				CalculateDamage();
				boomBoom->setHealth(boomBoom->getHealth() - damage);
				FVector impactSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 30.f, GetActorLocation().Z);
				UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, impactSpawnLocation, FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
			}
		}

		if (otherActor->IsA(AZipZap::StaticClass()))
		{
			if (AZipZap* zipZap = Cast<AZipZap>(otherActor))
			{
				CalculateDamage();
				zipZap->setHealth(zipZap->getHealth() - damage);
				FVector impactSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 30.f, GetActorLocation().Z);
				UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), zipZapImpact, impactSpawnLocation, FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
				FVector location = zipZap->GetActorLocation();
				location.Z += 30.f;
				location.Y -= 0.1f;
				AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, location, GetActorRotation());
				cfx->spriteChanger(1);
			}
		}

		if (!otherActor->IsA(ABoxTrigger::StaticClass()))
		{
			Destroy();
		}
	}
}

void ABullet::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}