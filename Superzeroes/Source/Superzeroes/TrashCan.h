// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Trash.h"
#include "TrashCan.generated.h"


#define ShootTime 3

/**
 * 
 */
UCLASS()
class SUPERZEROES_API ATrashCan : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	ATrashCan();
	~ATrashCan();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSpriteComponent* sprite;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* capsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* idle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* hurt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool trashMovingLeft;


	UFUNCTION(BlueprintCallable)
		float getHealth() { return health; };
	UFUNCTION(BlueprintCallable)
		void setHealth(float newHealth);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* hitbox;

	// time between shots fired by trash can
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float timeBetweenShoots;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool canSpawn;

	//Variable to keep track of trash can health
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health;

	float hurtTime;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATrash> Trash_BP;
};
