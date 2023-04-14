// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "FallingStairs.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API AFallingStairs : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	AFallingStairs();
	~AFallingStairs();
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* stairs;
	UFUNCTION(BlueprintCallable)
		void Activation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float stairsNumber;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isActivated;
};

