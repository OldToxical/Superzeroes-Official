// Fill out your copyright notice in the Description page of Project Settings.


#include "Toxic.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AToxic::AToxic()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetupAttachment(RootComponent);
}

AToxic::~AToxic()
{

}

void AToxic::BeginPlay()
{
	Super::BeginPlay();

}

void AToxic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AToxic::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
}

void AToxic::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	
}