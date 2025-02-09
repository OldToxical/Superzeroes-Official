// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "LAdder.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ALAdder : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	ALAdder();
	~ALAdder();
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* ladder;
	UFUNCTION(BlueprintCallable)
		void Activation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ladderNumber;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isActivated;
};
