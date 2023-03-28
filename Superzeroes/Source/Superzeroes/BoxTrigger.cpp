// Fill out your copyright notice in the Description page of Project Settings.
#include "BoxTrigger.h"
#include "ZipZap.h"
#include "Siege.h"
#include "Engine/EngineTypes.h"

ABoxTrigger::ABoxTrigger()
{
	colliderPlaneActor = NULL;
}

void ABoxTrigger::OverlapBegin(AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(AZipZap::StaticClass()) || otherActor->IsA(ASiege::StaticClass()))
		{
			if (colliderPlaneActor != NULL)
			{
				colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			}
		}
	}
}

void ABoxTrigger::OverlapEnd(AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(AZipZap::StaticClass()) || otherActor->IsA(ASiege::StaticClass()))
		{
			if (colliderPlaneActor != NULL)
			{
				colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
		}
	}
}