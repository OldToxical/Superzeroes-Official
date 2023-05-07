// Fill out your copyright notice in the Description page of Project Settings.


#include "Trash.h"
#include "TrashCan.h"
#include "PaperSpriteActor.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"

ATrash::ATrash()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	hitbox->SetupAttachment(RootComponent); 
	movingLeft = false;
}

ATrash::~ATrash()
{

}

void ATrash::BeginPlay()
{
	Super::BeginPlay();
	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ATrash::overlapBegin);
	hitbox->OnComponentEndOverlap.AddDynamic(this, &ATrash::overlapEnd);
}

void ATrash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime; //this is important so the trash doesnt destroy itself as soon as it is spawned
	if (movingLeft)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), -1.0, false);
		rotation.Pitch += 2.f;
		GetSprite()->SetWorldRotation(rotation);
	}
	else {
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.0, false);
		rotation.Pitch -= 2.f;
		GetSprite()->SetWorldRotation(rotation);
	}

	if(charMove->Velocity.X <= 0.2f && charMove->Velocity.X >= -0.2f && time > 1.0f)
	{
		Destroy(); //this destroys the trash as soon as it stops moving
	}
	
}


void ATrash::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		
		if (otherActor->ActorHasTag(TEXT("BoomBoom")))
		{
			ABoomBoom* boomBoom = (ABoomBoom*)otherActor;
			if (boomBoom->getHealth() > 0.0f)
			{
				boomBoom->setHealth(boomBoom->getHealth() - 10.f);
			}
			Destroy();
		}
		if (otherActor->ActorHasTag(TEXT("ZipZap")))
		{
			AZipZap* zipZap = (AZipZap*)otherActor;
			if (zipZap->getHealth() > 0.0f)
			{
				zipZap->setHealth(zipZap->getHealth() - 10.f);
			}
			Destroy();
		}
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			GetCapsuleComponent()->IgnoreActorWhenMoving(otherActor, true);
		}
	}
}

void ATrash::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		
	}
}