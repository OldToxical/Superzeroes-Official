// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Pigeon.h"
#include "Projectile.h"
#include "Math/Vector.h"
#include <chrono>
#include <thread>

AEnemy_Pigeon::AEnemy_Pigeon()
{
	srand(time(NULL));

	TArray<float, TFixedAllocator<6>> actionsAfterJumping;
	actionsAfterJumping.Add(35.f); // Go Idle
	actionsAfterJumping.Add(34.f); // Jump
	actionsAfterJumping.Add(50.f); // Walk Left
	actionsAfterJumping.Add(50.f); // Walk Right
	actionsAfterJumping.Add(65.f); // Attack
	actionsAfterJumping.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<6>> actionsAfterWalkingLeft;
	actionsAfterWalkingLeft.Add(35.f); // Go Idle
	actionsAfterWalkingLeft.Add(26.f); // Jump
	actionsAfterWalkingLeft.Add(47.f); // Walk Left
	actionsAfterWalkingLeft.Add(84.f); // Walk Right
	actionsAfterWalkingLeft.Add(85.f); // Attack
	actionsAfterWalkingLeft.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<6>> actionsAfterWalkingRight;
	actionsAfterWalkingRight.Add(35.f); // Go Idle
	actionsAfterWalkingRight.Add(26.f); // Jump
	actionsAfterWalkingRight.Add(85.f); // Walk Left
	actionsAfterWalkingRight.Add(47.f); // Walk Right
	actionsAfterWalkingRight.Add(86.f); // Attack
	actionsAfterWalkingRight.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<6>> actionsAfterAttacking;
	actionsAfterAttacking.Add(20.f); // Go Idle
	actionsAfterAttacking.Add(65.f); // Jump
	actionsAfterAttacking.Add(67.f); // Walk Left
	actionsAfterAttacking.Add(70.f); // Walk Right
	actionsAfterAttacking.Add(72.f); // Attack
	actionsAfterAttacking.Add(1.f); // Run Away

	TArray<float, TFixedAllocator<6>> actionsAfterRunningAway;
	actionsAfterRunningAway.Add(30.f); // Go Idle
	actionsAfterRunningAway.Add(0.f); // Jump
	actionsAfterRunningAway.Add(0.f); // Walk Left
	actionsAfterRunningAway.Add(0.f); // Walk Right
	actionsAfterRunningAway.Add(0.f); // Attack
	actionsAfterRunningAway.Add(100.f); // Run Away

	TArray<float, TFixedAllocator<6>> actionsAfterGoingIdle;
	actionsAfterGoingIdle.Add(40.f); // Go Idle
	actionsAfterGoingIdle.Add(44.f); // Jump
	actionsAfterGoingIdle.Add(70.f); // Walk Left
	actionsAfterGoingIdle.Add(67.f); // Walk Right
	actionsAfterGoingIdle.Add(72.f); // Attack
	actionsAfterGoingIdle.Add(0.f); // Run Away

	AI_Q.Add(actionsAfterGoingIdle);
	AI_Q.Add(actionsAfterJumping);
	AI_Q.Add(actionsAfterWalkingLeft);
	AI_Q.Add(actionsAfterWalkingRight);
	AI_Q.Add(actionsAfterAttacking);
	AI_Q.Add(actionsAfterRunningAway);

	currentState = State3::Idle;
	chooseActionTimeoutTimer = 2.f;
	stateUpdateTimer = 0.f;
	speed = 0.f;
	damage = 20.f;
	healthPoints = 50.f;
	difficulty = 1;
	inCombat = false;
}

void AEnemy_Pigeon::AI()
{
	ChooseAction();
	UpdateState();
}

void AEnemy_Pigeon::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy_Pigeon::Tick(float DeltaTime)
{
	AI();
}

void AEnemy_Pigeon::GetState()
{

}

void AEnemy_Pigeon::ChooseAction()
{
	if (chooseActionTimeoutTimer > 0.f)
	{
		chooseActionTimeoutTimer -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		TArray<float, TFixedAllocator<6>> possibleActions = AI_Q[currentState];
		float bestValue = 0.f;
		int actionsToBeChecked = possibleActions.Num();

		if (!inCombat)
		{
			actionsToBeChecked = 4;
		}

		for (int i = 0; i < actionsToBeChecked; i++)
		{
			if (bestValue < possibleActions[i])
			{
				bestValue = possibleActions[i];
				currentAction = Action(i);
			}
		}

		CalculateReward();
		ExecuteAction();
	}
}

void AEnemy_Pigeon::CalculateReward()
{
	float reward = 0.f;

	if (!inCombat)
	{
		reward = rand() % 10 + 5;
	}
	else // It's in combat, let's see what it did
	{
		// If siege mode is active - whatever it does, it won't escape and won't survive
		if (boomBoom->GetState() == State::Siege)
		{
			UpdateQ(reward);
			return;
		}

		float distanceToBoomBoom = (boomBoom->GetActorLocation() - GetActorLocation()).Size();

		// We need to see if he made the right decision depending on the state it's in
		if (currentState == State3::WalkingLeft) // It was walking left so far
		{
			if (currentAction == Action::WalkLeft) // It keeps walking left
			{
				// Check if it's going boom boom (not good)
				if (boomBoom->GetActorLocation().X < GetActorLocation().X)
				{
					reward -= (rand() % 8 + 3) * difficulty;

					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad
						reward -= (rand() % 10 + 6) * difficulty;
					}
					else
					{
						// Still bad, but there is still enough distance
						reward += (rand() % 7 + 2);
					}
				}
				else // It's not going to boom boom, that's good
				{
					reward += (rand() % 8 + 3);
				}
			    // Check if it's going zip zap (better to go to him, cuz he's weaker)
				if (zipZap->GetActorLocation().X < GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Boom Boom is around, so it's not that good
						reward -= (rand() % 4 + 1);
					}
					else
					{
						// Boom Boom is not around, perfect
						reward += (rand() % 6 + 2);
					}
				}
				else // It's going away from zip zap, that's not good
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Worse, it's going to Boom Boom
						reward -= (rand() % 6 + 2) * difficulty;
					}
					else
					{
						// It still goes to Boom Boom, but there is enough distance
						reward -= (rand() % 3 + 0);
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{
					reward -= (rand() % 6 + 1) * difficulty;
				}
			}
			else if (currentAction == Action::WalkRight) // It changes direction
			{
				// Check if he's going away from the direction of boom boom (good)
				if (boomBoom->GetActorLocation().X < GetActorLocation().X)
				{
					reward += (rand() % 8 + 4);
				}
				else // It's not going away from boom boom, not good, let's see how close he is
				{
					reward -= (rand() % 8 + 3) * difficulty;

					if (distanceToBoomBoom <= 150.f)
					{
						// Too close, that's very bad
						reward -= (rand() % 10 + 6) * difficulty;
					}
					else
					{
						// Not too close, not too bad
						reward += (rand() % 2 + 0);
					}
				}
				// Check if he's going away from the direction of zip zap (worse, because he has ranged attack)
				if (zipZap->GetActorLocation().X < GetActorLocation().X)
				{
					reward -= (rand() % 7 + 4) * difficulty;
				}
				else // It's going to zip zap, that's good, but let's see if boom boom is around
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// He is around, that's not very good
						reward += (rand() % 6 + 1);
					}
					else
					{
						// He is not around, perfect
						reward += (rand() % 12 + 7);
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{
					reward -= (rand() % 6 + 1) * difficulty;
				}
			}
			else if (currentAction == Action::Jump) // It jumps
			{
				// That's good, agility is good
				reward += (rand() % 5 + 2);

				// Check if zip zap shoots, it would be great to avoid his projectiles
				if (zipZap->GetState() == State2::Attacking)
				{
					reward += (rand() % 4 + 1);
				}
				// Check if there are any combo attacks active, if there are - that's reaaaally good
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{
					reward += (rand() % 5 + 2);
				}
			}
			else if (currentAction == Action::GoIdle)
			{
				// That's good (not too much) if both the characters are away (it looks like it's wondering where they are)
				float distanceToZipZap = (zipZap->GetActorLocation() - GetActorLocation()).Size();
				if (distanceToBoomBoom >= 300.f && distanceToZipZap >= 300.f)
				{
					reward += (rand() % 6 + 0);
				}
			}
			else if (currentAction == Action::Attack)
			{
				// That's good if it has health
				if (healthPoints >= 25.f)
				{
					reward += (rand() % 5 + 0);
				}
				// Better if the characters attack
				if (boomBoom->GetState() == State::Attacking || zipZap->GetState() == State2::Attacking)
				{
					reward += (rand() % 4 + 0);
				}
				// Even Better if the characters have combo attack active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{
					reward += (rand() % 7 + 3);
				}
			}
		}
		else if (currentState == State3::WalkingRight) // It was walking right so far
		{
			if (currentAction == Action::WalkRight) // It keeps walking right
			{
				// Check if he's going boom boom (not good)
			    if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{
					reward -= (rand() % 8 + 3) * difficulty;

					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad
						reward -= (rand() % 10 + 6) * difficulty;
					}
					else
					{
						// Better, there is still enough distance
						reward += (rand() % 7 + 2);
					}
				}
				else // It's not going to boom boom, that's good
				{
					reward += (rand() % 8 + 3);
				}
				// Check if he's going to zip zap, that's good, but let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Not so good, he's too close
						reward -= (rand() % 4 + 1);
					}
					else
					{
						// Very good, he's not around, zip zap is alone
						reward += (rand() % 6 + 2);
					}
				}
				else // It goes away from zip zap, that's not good
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
						reward -= (rand() % 6 + 2) * difficulty;
					}
					else
					{
						// Better, there is still enough distance
						reward -= (rand() % 3 + 0);
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{
					reward -= (rand() % 6 + 1) * difficulty;
				}
			}
			else if (currentAction == Action::WalkLeft) // It changes direction
			{
				// Check if he's going away from boom boom (good)
				if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{
					reward += (rand() % 8 + 3);
				}
				else // It's not going away from boom boom, that's bad
				{
					reward -= (rand() % 8 + 3) * difficulty;

					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, it's near boom boom and going even nearer
						reward -= (rand() % 10 + 6) * difficulty;
					}
					else
					{
						// Better, there is still enough distance
						reward += (rand() % 2 + 0);
					}
				}
				// Check if he's going away from zip zap (bad, because he has ranged attack), let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				else // It's going to zip zap, that's good, but let's see if boom boom is around
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Bad
					}
					else
					{
						// Good, boom boom isn't around
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{

				}
			}
			else if (currentAction == Action::Jump) // It jumps
			{
				// That's good, agility is good
				// Check if zip zap shoots, it would be great to avoid
			    // Check if there are any combo attacks active, if there are - that's reaaaally good
			}
			else if (currentAction == Action::GoIdle)
			{
				// That's good (not too much) if both the characters are away (it looks like it's wondering where they are)
				float distanceToZipZap = (zipZap->GetActorLocation() - GetActorLocation()).Size();
				if (distanceToBoomBoom >= 300.f && distanceToZipZap >= 300.f)
				{
	
				}
			}
			else if (currentAction == Action::Attack)
			{
				// That's good if it has health
				if (healthPoints >= 25.f)
				{

				}
				// Better if the characters attack
				if (boomBoom->GetState() == State::Attacking || zipZap->GetState() == State2::Attacking)
				{

				}
				// Even Better if the characters have combo attack active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
			}
		}
		else if (currentState == State3::Jumping) // It was jumping so far
		{
		    if (currentAction == Action::WalkRight) // It keeps walking right
		    {
			    // Check if he's going boom boom (not good)
			    if (boomBoom->GetActorLocation().X > GetActorLocation().X)
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Worse, very bad
				    }
				    else
				    {
					    // Better, there is still enough distance
				    }
			    }
			    else // It's not going to boom boom, that's good
			    {

			    }
			    // Check if he's going zip zap, that's good, but let's see if boom boom is around
			    if (zipZap->GetActorLocation().X > GetActorLocation().X)
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Not good
				    }
				    else
				    {
					    // Very good, he's not around, zip zap is alone
				    }
			    }
			    else // It goes away from zip zap, that's not good
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Very bad, going away from zip zap and going to boom boom
				    }
				    else
				    {
					    // Better, there is still enough distance
				    }
			    }
			    // Check if boom boom is attacking, it must be away from him
			    if (boomBoom->GetState() == State::Attacking)
			    {

			    }
		    }
		    else if (currentAction == Action::WalkLeft) // It changes direction
		    {
			    // Check if he's going away from boom boom (good)
			    if (boomBoom->GetActorLocation().X > GetActorLocation().X)
			    {

			    }
			    else // It's not going away from boom boom, that's bad
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Very bad, it's near boom boom and going even nearer
				    }
				    else
				    {
					    // Better, there is still enough distance
				    }
			    }
			    // Check if he's going away from zip zap (bad, because he has ranged attack), let's see if boom boom is around
			    if (zipZap->GetActorLocation().X > GetActorLocation().X)
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Very bad, going away from zip zap and going to boom boom
				    }
				    else
				    {
				    	// Better, there is still enough distance
				    }
			    }
			    else // It's going to zip zap, that's good, but let's see if boom boom is around
			    {
				    if (distanceToBoomBoom <= 150.f)
				    {
					    // Bad
				    }
				    else
					{
						// Very good, boom boom isn't around
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{

				}
			}
			else if (currentAction == Action::Jump) // It keeps jumping
			{
				// Two jumps after one another is not so good
			}
			else if (currentAction == Action::GoIdle)
			{
				// That's not the best thing to do after landing, especially if a combo attack is active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
			}
			else if (currentAction == Action::Attack)
			{
				// That's good if it has health
				if (healthPoints >= 25.f)
				{

				}
				// Better if the characters attack
				if (boomBoom->GetState() == State::Attacking || zipZap->GetState() == State2::Attacking)
				{

				}
				// Even Better if the characters have combo attack active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
			}
		}
		else if (currentState == State3::Idle) // It was idle so far
		{
			if (currentAction == Action::WalkLeft) // It decides to walk left
			{
				// Check if he's going away from boom boom (good)
				if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{

				}
				else // It's not going away from boom boom, that's bad
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, it's near boom boom and going even nearer
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				// Check if he's going away from zip zap (bad, because he has ranged attack), let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				else // It's going to zip zap, that's good, but let's see if boom boom is around
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Bad
					}
					else
					{
						// Good, boom boom isn't around
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{

				}
			}
			else if (currentAction == Action::WalkRight) // It It decides to walk right
			{
				// Check if he's going boom boom (not good)
				if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Worse, very bad
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				else // It's not going to boom boom, that's good
				{

				}
				// Check if he's going zip zap, that's good, but let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Not good
					}
					else
					{
						// Very good, he's not around, zip zap is alone
					}
				}
				else // It goes away from zip zap, that's not good
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{

				}
			}
			else if (currentAction == Action::Jump) // It decides to jump
			{
				// Jumping on one place is not good
			}
			else if (currentAction == Action::GoIdle)
			{
				// That's not the best thing to do after having been idle so far, especially if a combo attack is active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
			}
			else if (currentAction == Action::Attack)
			{
				// That's good if it has health
				if (healthPoints >= 25.f)
				{

				}
				// Better if the characters attack
				if (boomBoom->GetState() == State::Attacking || zipZap->GetState() == State2::Attacking)
				{

				}
				// Even Better if the characters have combo attack active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
			}
		}
		else if (currentState == State3::Attacking) // It was attacking so far
		{
			if (currentAction == Action::WalkLeft) // It decides to walk left
			{
				// Check if he's going away from boom boom (good)
				if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{

				}
				else // It's not going away from boom boom, that's bad
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, it's near boom boom and going even nearer
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				// Check if he's going away from zip zap (bad, because he has ranged attack), let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
					}
					else
					{
						// Better, there is still enough distance
					}
				}
			else // It's going to zip zap, that's good, but let's see if boom boom is around
			{
				if (distanceToBoomBoom <= 150.f)
				{
					// Bad
				}
				else
				{
					// Good, boom boom isn't around
				}
			}
			// Check if boom boom is attacking, it must be away from him
			if (boomBoom->GetState() == State::Attacking)
			{

			}
		}
			else if (currentAction == Action::WalkRight) // It It decides to walk right
			{
				// Check if he's going boom boom (not good)
				if (boomBoom->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Worse, very bad
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				else // It's not going to boom boom, that's good
				{

				}
				// Check if he's going zip zap, that's good, but let's see if boom boom is around
				if (zipZap->GetActorLocation().X > GetActorLocation().X)
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Not good
					}
					else
					{
						// Very good, he's not around, zip zap is alone
					}
				}
				else // It goes away from zip zap, that's not good
				{
					if (distanceToBoomBoom <= 150.f)
					{
						// Very bad, going away from zip zap and going to boom boom
					}
					else
					{
						// Better, there is still enough distance
					}
				}
				// Check if boom boom is attacking, it must be away from him
				if (boomBoom->GetState() == State::Attacking)
				{

				}
			}
		    else if (currentAction == Action::Jump) // It decides to jump
		    {
			    // Agility is good, especially if a combo attack is active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
		    }
		    else if (currentAction == Action::GoIdle)
		    {
			    // If a combo attack is active, it's noot good, otherwise - if it's away from the characters
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}

				float distanceToZipZap = (zipZap->GetActorLocation() - GetActorLocation()).Size();
				if (distanceToBoomBoom >= 300.f && distanceToZipZap >= 300.f)
				{

				}
		    }
		    else if (currentAction == Action::Attack)
		    {
				// It's not very good to repeat attack
				
				// Repeat attack only if there are combo attacks active
				if (zipZap->GetState() == State2::Combo_Projectile || boomBoom->GetState() == State::Combo_Savage)
				{

				}
		    }
        }
	}

	UpdateQ(reward);
}

void AEnemy_Pigeon::UpdateQ(float reward)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("State: ") + FString::SanitizeFloat(currentState));
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Action: ") + FString::SanitizeFloat(currentAction));
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Current Q: ") + FString::SanitizeFloat(AI_Q[currentState][currentAction]));
	AI_Q[currentState][currentAction] = AI_Q[currentState][currentAction] + Q_LearningRate * ((reward + Q_DiscountFactor * Q_EstimatedOptimalFutureValue) - AI_Q[currentState][currentAction]);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("New Q: ") + FString::SanitizeFloat(AI_Q[currentState][currentAction]));
}

void AEnemy_Pigeon::ExecuteAction()
{
	if (currentAction == Action::GoIdle)
	{
		currentState = State3::Idle;
	}
	else if (currentAction == Action::Jump)
	{
		currentState = State3::Jumping;
	}
	else if (currentAction == Action::WalkLeft)
	{
		speed = characterMovementComponent->MaxWalkSpeed / 7.f;
		newX = FMath::RandRange(GetActorLocation().X - 30, GetActorLocation().X - 90);
		float distanceToTravel = abs(GetActorLocation().X - newX);
		stateUpdateTimer = distanceToTravel / speed;
		chooseActionTimeoutTimer = (stateUpdateTimer *= 1.5f);
		currentState = State3::WalkingLeft;
	}
	else if (currentAction == Action::WalkRight)
	{
		speed = characterMovementComponent->MaxWalkSpeed / 7.f;
		newX = FMath::RandRange(GetActorLocation().X + 30, GetActorLocation().X + 90);
		float distanceToTravel = abs(GetActorLocation().X - newX);
		stateUpdateTimer = distanceToTravel / speed;
		chooseActionTimeoutTimer = (stateUpdateTimer *= 1.5f);
		currentState = State3::WalkingRight;
	}
	else if (currentAction == Action::Attack)
	{
		currentState = State3::Attacking;
		stateUpdateTimer = ShootingAnimationLength;
		chooseActionTimeoutTimer = stateUpdateTimer;
	}
	else if (currentAction == Action::RunAway)
	{
		currentState = State3::RunningAway;
	}
}

void AEnemy_Pigeon::UpdateState()
{
	SetActorLocation(FVector(GetActorLocation().X, .5f, GetActorLocation().Z));

	switch (currentState)
	{
	case State3::Idle:
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(idle);
			flipbookComponent->SetLooping(true);
		}
		break;

	case State3::Jumping:
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(jumpAnim);
			flipbookComponent->SetLooping(false);
			Jump();
		}
		break;

	case State3::WalkingLeft:
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
			WalkLeft();
		}
		break;

	case State3::WalkingRight:
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
			WalkRight();
		}
		break;

	case State3::Attacking:
		flipbookComponent->SetFlipbook(attack);
		flipbookComponent->SetLooping(false);
		Attack();
		break;

	case State3::RunningAway:
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
		}
		break;

	default:
		break;
	}

	// AI Sensing
	if (boomBoom != nullptr && zipZap != nullptr)
	{
		if ((abs(GetActorLocation().X - boomBoom->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - boomBoom->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ))
		{
			inCombat = true;
			playerToAttack = boomBoom;
		}

		if ((abs(GetActorLocation().X - zipZap->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - zipZap->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ))
		{
			inCombat = true;
			playerToAttack = zipZap;
		}
	}

	// Check Health
	if (healthPoints <= 0.f)
	{
		if (spawner != nullptr)
		{
			spawner->RemoveEnemy(this);
		}
		Destroy();
	}
}

void AEnemy_Pigeon::WalkLeft()
{
	if (stateUpdateTimer > 0.f)
	{
		stateUpdateTimer -= GetWorld()->GetDeltaSeconds();
		AddMovementInput(FVector(-1.f, 0.f, 0.f), 0.3f, false);
		rotation.Yaw = 0.f;
		flipbookComponent->SetWorldRotation(rotation);
	}
}

void AEnemy_Pigeon::WalkRight()
{
	if (stateUpdateTimer > 0.f)
	{
		stateUpdateTimer -= GetWorld()->GetDeltaSeconds();
		AddMovementInput(FVector(1.f, 0.f, 0.f), 0.3f, false);
		rotation.Yaw = 180.f;
		flipbookComponent->SetWorldRotation(rotation);
	}
}

void AEnemy_Pigeon::Attack()
{
	// Wait until the needed frame is executed
	if (stateUpdateTimer > 0.f)
	{
		stateUpdateTimer -= GetWorld()->GetDeltaSeconds();
		FaceNearestPlayer();
	}
	else // The frame is on the screen, execute the actual attacking functionality once
	{
		FaceNearestPlayer();

		FVector muzzleFlashLocation = FVector(GetActorLocation().X - 45.34f, GetActorLocation().Y, GetActorLocation().Z + 13.f);
		FRotator bulletLookAtVector = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), playerToAttack->GetActorLocation());

		if (rotation.Yaw > 0.f) // Right
		{
			muzzleFlashLocation.X += 90.68f;
		}

		// Spawn muzzle flash particle
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), muzzleFlashParticle, muzzleFlashLocation);

		// Spawn bullet
		AProjectile* bullet = GetWorld()->SpawnActor<AProjectile>(bulletClass, muzzleFlashLocation, bulletLookAtVector);
	}
}

void AEnemy_Pigeon::RunAway()
{
}

void AEnemy_Pigeon::FaceNearestPlayer()
{
	if (playerToAttack->ActorHasTag("BoomBoom"))
	{
		// Face him
		if (boomBoom->GetActorLocation().X < GetActorLocation().X) // He's on the left
		{
			rotation.Yaw = 0.f;
			flipbookComponent->SetWorldRotation(rotation);

		}
		else // He's on the right
		{
			rotation.Yaw = 180.f;
			flipbookComponent->SetWorldRotation(rotation);
		}

		return;
	}
	
	// Zip Zap is closer, face him
	if (zipZap->GetActorLocation().X < GetActorLocation().X) // He's on the left
	{
		rotation.Yaw = 0.f;
		flipbookComponent->SetWorldRotation(rotation);

	}
	else // He's on the right
	{
		rotation.Yaw = 180.f;
		flipbookComponent->SetWorldRotation(rotation);
	}
}

void AEnemy_Pigeon::EndAttack()
{
	if (flipbookComponent->GetFlipbook() == hurtAnim)
	{
		flipbookComponent->SetFlipbook(idle);
	}

	flipbookComponent->SetLooping(true);
	flipbookComponent->Play();
}

void AEnemy_Pigeon::TakeEnemyDamage(float damage_)
{
	healthPoints -= damage_;
	flipbookComponent->SetFlipbook(hurtAnim);
	flipbookComponent->SetLooping(false);
}