// Fill out your copyright notice in the Description page of Project Settings.
#include "BoxTriggerBoomBoom.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Engine/EngineTypes.h"

ABoxTriggerBoomBoom::ABoxTriggerBoomBoom()
{
	colliderPlaneActor = NULL;
}

void ABoxTriggerBoomBoom::OverlapBegin(AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		if (otherActor->IsA(ABoomBoom::StaticClass()))
		{
			if (colliderPlaneActor != NULL)
			{
				colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			}
		}
	}
}

void ABoxTriggerBoomBoom::OverlapEnd()
{
	if (colliderPlaneActor != NULL)
	{
		colliderPlaneActor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}