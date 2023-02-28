// Fill out your copyright notice in the Description page of Project Settings.


#include "Trash.h"
#include "Components/BoxComponent.h"
#include "BoomBoom.h"
#include "ZipZap.h"

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

void ATrash::HitCheck()
{
	TArray<AActor*> boom;
	TArray<AActor*> zip;
	GetOverlappingActors(boom, ABoomBoom::StaticClass());
	GetOverlappingActors(zip, AZipZap::StaticClass());
	// Go through each overlapping body
	for (int i = 0; i < boom.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("FROTTING!"));
	}
	if (zip.Num() > 0 || boom.Num() > 0)
	{
		Destroy();
	}
}

void ATrash::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		if (otherActor->IsA(ABoomBoom::StaticClass()) || otherActor->IsA(AZipZap::StaticClass()))
		{
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