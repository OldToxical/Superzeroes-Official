// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "ComicFX.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API AComicFX : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	AComicFX();
	~AComicFX();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void spriteChanger(int i);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* zap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* squeak; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* squawk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* bang; 

protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			FVector location;
};
