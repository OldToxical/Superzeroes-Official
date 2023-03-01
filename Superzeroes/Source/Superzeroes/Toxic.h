// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Toxic.generated.h"

/**
 *
 */
UCLASS()
class SUPERZEROES_API AToxic : public APaperSpriteActor
{
	GENERATED_BODY()
public:
	AToxic();
	~AToxic();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;

};