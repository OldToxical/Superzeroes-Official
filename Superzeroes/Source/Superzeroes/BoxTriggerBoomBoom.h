// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BoxTriggerBoomBoom.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ABoxTriggerBoomBoom : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	ABoxTriggerBoomBoom();

	UFUNCTION(BlueprintCallable)
		void OverlapBegin(AActor* otherActor);
	UFUNCTION(BlueprintCallable)
		void OverlapEnd(AActor* otherActor);

	UPROPERTY(BlueprintReadWrite)
		UStaticMeshComponent* colliderPlaneActor;
};
