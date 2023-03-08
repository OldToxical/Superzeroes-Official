// Fill out your copyright notice in the Description page of Project Settings.
#include "BoxTrigger.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Engine/EngineTypes.h"

ABoxTrigger::ABoxTrigger()
{
	colliderPlaneActor = NULL;
}

void ABoxTrigger::OverlapBegin(AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(AZipZap::StaticClass()) || otherActor->IsA(ABoomBoom::StaticClass()))
		{
			if (colliderPlaneActor != NULL)
			{
				colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::White, TEXT("vliza"));
			}
		}
	}
}

void ABoxTrigger::OverlapEnd()
{
	if (colliderPlaneActor != NULL)
	{
		colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::White, TEXT("izliza"));
	}
}