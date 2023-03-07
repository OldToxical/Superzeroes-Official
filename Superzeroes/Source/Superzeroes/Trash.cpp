// Fill out your copyright notice in the Description page of Project Settings.


#include "Trash.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Kismet/GameplayStatics.h"

ATrash::ATrash()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(0.75, 0.75, 0.75));
	hitbox->SetupAttachment(RootComponent); 
}

ATrash::~ATrash()
{

}

void ATrash::BeginPlay()
{
	Super::BeginPlay();
	charMove = GetCharacterMovement();
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ATrash::overlapBegin);
	hitbox->OnComponentEndOverlap.AddDynamic(this, &ATrash::overlapEnd);
	Jump();
}

void ATrash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(FVector(0.3f, 0.0f, 0.0f), 1.0, false);
}


void ATrash::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		if (!otherActor->ActorHasTag(TEXT("Floor")))
		{
			Destroy();
		}
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
	}
}

void ATrash::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		//UE_LOG(LogTemp, Warning, TEXT("i am gaming!"));
	}
}