// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Frog_Test.generated.h"

enum State 
{
	Idle,
	Jumping,
	WalkingLeft,
	WalkingRight,
	Attacking,
	RunningAway
};

enum Action
{
	Jump,
	WalkLeft,
	WalkRight,
	Attack,
	RunAway
};

UCLASS()
class SUPERZEROES_API AFrog_Test : public AEnemy
{
	GENERATED_BODY()

private:
	AFrog_Test();

	virtual void AI() override;
	virtual void Tick(float DeltaTime) override;

	// AI Functions
	void GetState();
	void ChooseAction();
	void CalculateReward();
	void UpdateQ(float reward);

	State currentState;
	Action currentAction;
	TArray<TArray<float, TFixedAllocator<5>>, TFixedAllocator<5>> AI_Q;

	//std::array<std::array<float, ACTION_NUM>, STATE_NUM> Q = { {0} };
};
