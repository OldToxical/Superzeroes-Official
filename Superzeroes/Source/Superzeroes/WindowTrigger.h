// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoxTriggerBoomBoom.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "WindowTrigger.generated.h"

/**
 *
 */
UCLASS()
class SUPERZEROES_API AWindowTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	AWindowTrigger();

	void BreakWindow();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* flipbook;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<UPaperSpriteComponent*> windowPoles;
};