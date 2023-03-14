// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "Button_But_Awesome.generated.h"

/**
 * 
 */
UCLASS()
class SUPERZEROES_API AButton_But_Awesome : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	AButton_But_Awesome();
	~AButton_But_Awesome();

	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* pressed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* not_pressed;
	UFUNCTION(BlueprintCallable)
		void ButtPress();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float buttonNumber;
};
