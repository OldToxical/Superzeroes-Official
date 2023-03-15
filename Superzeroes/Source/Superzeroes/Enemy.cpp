// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

AEnemy::AEnemy()
{
	characterMovementComponent = NULL;
	flipbookComponent = NULL;
	healthPoints = 100.f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UpdateActorState();
	//UpdateRotation();
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	characterMovementComponent = GetCharacterMovement();

	if (flipbookComponent)
	{
		flipbookComponent->bOwnerNoSee = false;
		flipbookComponent->bAffectDynamicIndirectLighting = true;
		flipbookComponent->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		flipbookComponent->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		flipbookComponent->SetCollisionProfileName(CollisionProfileName);
		flipbookComponent->SetGenerateOverlapEvents(false);
	}
}

void AEnemy::AI()
{
}

void AEnemy::UpdateAnimation()
{
	
}

void AEnemy::UpdateRotation()
{
	if (characterMovementComponent)
	{
		if (characterMovementComponent->Velocity.X > 0.f)
		{
			rotation.Yaw = 0.f;
		}
		else
		{
			rotation.Yaw = 180.f;
		}

		GetCapsuleComponent()->SetRelativeRotation(rotation);
	}
}

void AEnemy::TakeEnemyDamage(float damage_)
{
}
