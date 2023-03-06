// Fill out your copyright notice in the Description page of Project Settings.

///Tozi komentar e po-dulag ot pishkata mi

#include "TestSphere.h"

// Sets default values
ATestSphere::ATestSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(FVector(GetActorLocation().X + 1.f, GetActorLocation().Y, GetActorLocation().Z));
}

