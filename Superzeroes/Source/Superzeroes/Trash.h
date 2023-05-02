// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Trash.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class trashState : uint8
 {
	 Idle,
	 Hurt
 };
UCLASS()
class SUPERZEROES_API ATrash : public APaperCharacter
{
	GENERATED_BODY()
public:
	ATrash();
	~ATrash();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCharacterMovementComponent* charMove;

	UFUNCTION(BlueprintCallable)
		void overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result);
	UFUNCTION(BlueprintCallable)
		void overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
			UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool movingLeft;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* hitbox;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FRotator rotation;

	float time;



};
