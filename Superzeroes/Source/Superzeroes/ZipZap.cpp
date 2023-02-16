// Fill out your copyright notice in the Description page of Project Settings.


#include "ZipZap.h"
#include "Components/CapsuleComponent.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AZipZap::AZipZap()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 

	flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	if (flipbook)
	{
		flipbook->bOwnerNoSee = false;
		flipbook->bAffectDynamicIndirectLighting = true;
		flipbook->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		flipbook->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		flipbook->SetCollisionProfileName(CollisionProfileName);
		flipbook->SetGenerateOverlapEvents(false);
	}
}

// Called when the game starts or when spawned
void AZipZap::BeginPlay()
{
	Super::BeginPlay();
	flipbook->SetFlipbook(idle);
	rotation = FRotator::ZeroRotator;
}

// Called every frame
void AZipZap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();
	UpdateRotation();
}

void AZipZap::UpdateAnimation()
{
	//get character movement component
	charMove = GetCharacterMovement();
	//if character is moving, change to running animation
	if (charMove->Velocity.Size() > 0.0)
	{
		flipbook->SetFlipbook(run); 
		//if character is jumping, change to jump animation
		if (charMove->IsFalling())
		{
			flipbook->SetFlipbook(jumping);
		}
		//UE_LOG(LogTemp, Warning, TEXT("schmoving"));
	}
	
	else
	{ //otherwise, change to idle animation
		flipbook->SetFlipbook(idle);
	}
}

void AZipZap::move(float scaleVal)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);
}

void AZipZap::UpdateRotation()
{
	//get character movement component
	charMove = GetCharacterMovement();
	//if character is moving right, set sprite to face right
	if (charMove->Velocity.X > 0.0)
	{
		rotation.Yaw = 0.0f;
	}
	//if character is moving left, set sprite to face left
	if (charMove->Velocity.X < 0.0)
	{
		rotation.Yaw = 180.0f;
	}
	GetCapsuleComponent()->SetRelativeRotation(rotation);
}