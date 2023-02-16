// Fill out your copyright notice in the Description page of Project Settings.


#include "Frog_Test.h"
#include <chrono>
#include <thread>

AFrog_Test::AFrog_Test()
{
	srand(time(NULL));

	TArray<float, TFixedAllocator<5>> actionsAfterJumping;
	actionsAfterJumping.Add(34.f); // Jump
	actionsAfterJumping.Add(50.f); // Walk Left
	actionsAfterJumping.Add(38.f); // Walk Right
	actionsAfterJumping.Add(70.f); // Attack
	actionsAfterJumping.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<5>> actionsAfterWalkingLeft;
	actionsAfterWalkingLeft.Add(100.f); // Jump
	actionsAfterWalkingLeft.Add(0.f); // Walk Left
	actionsAfterWalkingLeft.Add(0.f); // Walk Right
	actionsAfterWalkingLeft.Add(0.f); // Attack
	actionsAfterWalkingLeft.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<5>> actionsAfterWalkingRight;
	actionsAfterWalkingRight.Add(0.f); // Jump
	actionsAfterWalkingRight.Add(100.f); // Walk Left
	actionsAfterWalkingRight.Add(0.f); // Walk Right
	actionsAfterWalkingRight.Add(0.f); // Attack
	actionsAfterWalkingRight.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<5>> actionsAfterAttacking;
	actionsAfterAttacking.Add(65.f); // Jump
	actionsAfterAttacking.Add(48.f); // Walk Left
	actionsAfterAttacking.Add(70.f); // Walk Right
	actionsAfterAttacking.Add(60.f); // Attack
	actionsAfterAttacking.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<5>> actionsAfterRunningAway;
	actionsAfterRunningAway.Add(0.f); // Jump
	actionsAfterRunningAway.Add(0.f); // Walk Left
	actionsAfterRunningAway.Add(0.f); // Walk Right
	actionsAfterRunningAway.Add(0.f); // Attack
	actionsAfterRunningAway.Add(100.f); // Run Away

	AI_Q.Add(actionsAfterJumping);
	AI_Q.Add(actionsAfterWalkingLeft);
	AI_Q.Add(actionsAfterWalkingRight);
	AI_Q.Add(actionsAfterAttacking);

	currentState = State::Idle;
}

void AFrog_Test::AI()
{
	ChooseAction();
	CalculateReward();
}

void AFrog_Test::Tick(float DeltaTime)
{
	AI();
}

void AFrog_Test::GetState()
{

}

void AFrog_Test::ChooseAction()
{
	TArray<float, TFixedAllocator<5>> possibleActions = AI_Q[currentState];
	float bestValue = 0.f;

	for (int i = 0; i < possibleActions.Num(); i++)
	{
		if (bestValue < possibleActions[i])
		{
			bestValue = possibleActions[i];
			currentAction = Action(i);
		}
	}
}

void AFrog_Test::CalculateReward()
{
	if (currentState == State::WalkingLeft || currentState == State::WalkingRight)
	{
		float reward = rand() % 10 + 5;
		UpdateQ(reward);
	}
}

void AFrog_Test::UpdateQ(float reward)
{
	//AI_Q[state][action] = (*Q)[state][action] + 0.1f * ((reward + 0.3f * 20.f) - (*Q)[state][action]);
}