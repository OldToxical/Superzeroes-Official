// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashCan.h"

ATrashCan::ATrashCan()
{
	PrimaryActorTick.bCanEverTick = true;
	sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	sprite->SetupAttachment(RootComponent);
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	capsule->SetupAttachment(RootComponent);
}

ATrashCan::~ATrashCan()
{

}

void ATrashCan::BeginPlay()
{
	Super::BeginPlay();
	timeBetweenShoots = 0.0f;
}

void ATrashCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeBetweenShoots += DeltaTime;
	if (timeBetweenShoots >= ShootTime)
	{
		FVector location (GetActorLocation().X, GetActorLocation().Y + 0.4f, GetActorLocation().Z + 50.0f);
		if (Trash_BP)
		{
			GetWorld()->SpawnActor<ATrash>(Trash_BP,location,GetActorRotation());
		}
		timeBetweenShoots = 0.0f;
	}
}