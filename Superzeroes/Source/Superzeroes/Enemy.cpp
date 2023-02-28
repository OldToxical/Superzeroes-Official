// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

AEnemy::AEnemy()
{
	characterMovementComponent = NULL;
	flipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	idle = NULL;
	flipbookComponent = NULL;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

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

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	flipbookComponent->SetFlipbook(idle);
	funny = true;
	UpdateRotation();
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	characterMovementComponent = GetCharacterMovement();
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

void AEnemy::moveLeft(float scaleVal)
{
	AddMovementInput(FVector(-1.0f, 0.0f, 0.0f), scaleVal, false);
}

void AEnemy::moveRight(float scaleVal)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);
}

