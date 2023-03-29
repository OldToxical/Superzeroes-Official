// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Trash.h"
#include "TrashCan.generated.h"


#define ShootTime 5

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSpriteComponent* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* capsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* idle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// time between shots fired by trash can
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float timeBetweenShoots;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATrash> Trash_BP;
};
