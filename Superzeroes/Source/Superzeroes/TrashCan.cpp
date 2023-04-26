// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashCan.h"
#include "Components/BoxComponent.h"

ATrashCan::ATrashCan()
{
	PrimaryActorTick.bCanEverTick = true;
	sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	sprite->SetupAttachment(RootComponent);
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	capsule->SetupAttachment(RootComponent);
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	hitbox->SetupAttachment(RootComponent); 
	trashMovingLeft = false;
	canSpawn = true;
}

ATrashCan::~ATrashCan()
{

}

void ATrashCan::BeginPlay()
{
	Super::BeginPlay();
	timeBetweenShoots = 0.0f;
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ATrashCan::overlapBegin);
	hitbox->OnComponentEndOverlap.AddDynamic(this, &ATrashCan::overlapEnd);
}

void ATrashCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeBetweenShoots += DeltaTime;
	if (timeBetweenShoots >= ShootTime && canSpawn == true)
	{
		FVector location (GetActorLocation().X, GetActorLocation().Y + 0.4f, GetActorLocation().Z + 150.0f);
		if (Trash_BP)
		{
			ATrash* trash = GetWorld()->SpawnActor<ATrash>(Trash_BP,location,GetActorRotation());
			if (trashMovingLeft)
			{
				trash->movingLeft = true;
			}
		}
		timeBetweenShoots = 0.0f;
	}
}

void ATrashCan::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		if (otherActor->ActorHasTag(TEXT("BoomBoom")) || otherActor->ActorHasTag(TEXT("ZipZap")))
		{
			canSpawn = false;
		}
	}
}

void ATrashCan::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && (otherActor != this) && otherComp)
	{	
		if (otherActor->ActorHasTag(TEXT("BoomBoom")) || otherActor->ActorHasTag(TEXT("ZipZap")))
		{
			canSpawn = true;
		}
	}
}