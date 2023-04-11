// Fill out your copyright notice in the Description page of Project Settings.
#include "ElectricCharge.h"
#include "Button_But_Awesome.h"
#include "BoxTrigger.h"
#include "Siege.h"
#include "ComicFX.h"

AElectricCharge::AElectricCharge()
{
	damage = 20.f;
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
				FVector impactForce = FVector(330.f, 0.f, 180.f);
				if (GetActorLocation().X > Enemy->GetActorLocation().X) // Looking left
				{
					impactForce.X *= -1.f;
				}
				Enemy->LaunchCharacter(impactForce, false, false);
				Enemy->TakeEnemyDamage(damage);
				AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, FVector(Enemy->GetActorLocation().X, Enemy->GetActorLocation().Y, Enemy->GetActorLocation().Z + 80.f), GetActorRotation());
				cfx->spriteChanger(0);
			}
		}
				
		if (otherActor->ActorHasTag("Button"))
		{
			if (AButton_But_Awesome* button = Cast<AButton_But_Awesome>(otherActor))
			{
				float distanceTravelled = (startPos - GetActorLocation()).Size();
				if (((startPos - GetActorLocation()).Size()) <= 200.f)
				{
					button->ButtPress();
				}
			}
		}

		if (!otherActor->IsA(ABoxTrigger::StaticClass()) && !otherActor->IsA(ABoomBoom::StaticClass()) && !otherActor->IsA(AZipZap::StaticClass()) && !otherActor->IsA(ASiege::StaticClass()))
		{
			FVector impactDebrisSpawnLocation = FVector(GetActorLocation().X, 1.f, GetActorLocation().Z);
			UParticleSystemComponent* impactDebris = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), impactParticle, impactDebrisSpawnLocation, FRotator(0.f, 0.f, 0.f), FVector(.5f, .5f, .5f));
			Destroy();
		}
	}
}

void AElectricCharge::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}