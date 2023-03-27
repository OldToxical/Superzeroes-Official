// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy_Mouse.h"
#include "Components/BoxComponent.h"
#include "ComicFX.h"
#include <chrono>
#include <thread>

AEnemy_Mouse::AEnemy_Mouse()
{
	srand(time(NULL));

	TArray<float, TFixedAllocator<4>> actionsAfterJumping;
	actionsAfterJumping.Add(35.f); // Go Idle
	actionsAfterJumping.Add(34.f); // Jump
	actionsAfterJumping.Add(50.f); // Walk Left
	actionsAfterJumping.Add(38.f); // Walk Right

	TArray<float, TFixedAllocator<4>> actionsAfterWalkingLeft;
	actionsAfterWalkingLeft.Add(35.f); // Go Idle
	actionsAfterWalkingLeft.Add(26.f); // Jump
	actionsAfterWalkingLeft.Add(47.f); // Walk Left
	actionsAfterWalkingLeft.Add(84.f); // Walk Right

	TArray<float, TFixedAllocator<4>> actionsAfterWalkingRight;
	actionsAfterWalkingRight.Add(35.f); // Go Idle
	actionsAfterWalkingRight.Add(26.f); // Jump
	actionsAfterWalkingRight.Add(85.f); // Walk Left
	actionsAfterWalkingRight.Add(47.f); // Walk Right

	TArray<float, TFixedAllocator<4>> actionsAfterGoingIdle;
	actionsAfterGoingIdle.Add(40.f); // Go Idle
	actionsAfterGoingIdle.Add(44.f); // Jump
	actionsAfterGoingIdle.Add(70.f); // Walk Left
	actionsAfterGoingIdle.Add(67.f); // Walk Right

	AI_Q.Add(actionsAfterGoingIdle);
	AI_Q.Add(actionsAfterJumping);
	AI_Q.Add(actionsAfterWalkingLeft);
	AI_Q.Add(actionsAfterWalkingRight);

	currentState = State4::Idle;
	chooseActionTimeoutTimer = 2.f;
	stateUpdateTimer = 0.f;
	speed = 0.f;
	damage = 30.f;
	healthPoints = 100.f;
	hitAvailable = true;
	inCombat = false;
}

void AEnemy_Mouse::AI()
{
	ChooseAction();
	UpdateState();
}

void AEnemy_Mouse::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy_Mouse::Tick(float DeltaTime)
{
	AI();
}

void AEnemy_Mouse::TakeEnemyDamage(float damage_)
{
	healthPoints -= damage_;
	flipbookComponent->SetFlipbook(hurtAnim);
	flipbookComponent->SetLooping(false);
}

void AEnemy_Mouse::GetState()
{

}

void AEnemy_Mouse::ChooseAction()
{
	if (!inCombat && currentState != State4::Dead)
	{
		if (chooseActionTimeoutTimer > 0.f)
		{
			chooseActionTimeoutTimer -= GetWorld()->GetDeltaSeconds();
		}
		else
		{
			TArray<float, TFixedAllocator<4>> possibleActions = AI_Q[currentState];
			float bestValue = 0.f;

			for (int i = 0; i < 4; i++)
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
	else if (inCombat && currentState != State4::Dead)
	{
		Attack();
	}
}

void AEnemy_Mouse::CalculateReward()
{
	float reward = rand() % 10 + 5;
	UpdateQ(reward);
}

void AEnemy_Mouse::UpdateQ(float reward)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("State: ") + FString::SanitizeFloat(currentState));
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Action: ") + FString::SanitizeFloat(currentAction));
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Current Q: ") + FString::SanitizeFloat(AI_Q[currentState][currentAction]));
	AI_Q[currentState][currentAction] = AI_Q[currentState][currentAction] + Q_LearningRate * ((reward + Q_DiscountFactor * Q_EstimatedOptimalFutureValue) - AI_Q[currentState][currentAction]);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("New Q: ") + FString::SanitizeFloat(AI_Q[currentState][currentAction]));
}

void AEnemy_Mouse::ExecuteAction()
{
	if (currentAction == Action::GoIdle)
	{
		currentState = State4::Idle;
	}
	else if (currentAction == Action::Jump)
	{
		currentState = State4::Jumping;
	}
	else if (currentAction == Action::WalkLeft)
	{
		speed = characterMovementComponent->MaxWalkSpeed / 7.f;
		newX = FMath::RandRange(GetActorLocation().X - 30, GetActorLocation().X - 90);
		float distanceToTravel = abs(GetActorLocation().X - newX);
		stateUpdateTimer = distanceToTravel / speed;
		chooseActionTimeoutTimer = (stateUpdateTimer *= 1.5f);
		currentState = State4::WalkingLeft;
	}
	else if (currentAction == Action::WalkRight)
	{
		speed = characterMovementComponent->MaxWalkSpeed / 7.f;
		newX = FMath::RandRange(GetActorLocation().X + 30, GetActorLocation().X + 90);
		float distanceToTravel = abs(GetActorLocation().X - newX);
		stateUpdateTimer = distanceToTravel / speed;
		chooseActionTimeoutTimer = (stateUpdateTimer *= 1.5f);
		currentState = State4::WalkingRight;
	}
}

void AEnemy_Mouse::UpdateState()
{
	SetActorLocation(FVector(GetActorLocation().X, .5f, GetActorLocation().Z));

	switch (currentState)
	{
	    case State4::Idle:
			if (flipbookComponent->GetFlipbook() != hurtAnim)
			{
				flipbookComponent->SetFlipbook(idle);
				flipbookComponent->SetLooping(true);
			}
			break;
		case State4::Jumping:
			if (flipbookComponent->GetFlipbook() != hurtAnim)
			{
				flipbookComponent->SetFlipbook(jumpAnim);
				flipbookComponent->SetLooping(false);
			}
			Jump();
			break;
		case State4::WalkingLeft:
			if (flipbookComponent->GetFlipbook() != hurtAnim)
			{
				flipbookComponent->SetFlipbook(walk);
				flipbookComponent->SetLooping(true);
			}
			WalkLeft();
			break;
		case State4::WalkingRight:
			if (flipbookComponent->GetFlipbook() != hurtAnim)
			{
				flipbookComponent->SetFlipbook(walk);
				flipbookComponent->SetLooping(true);
			}
			WalkRight();
			break;
		case State4::Dead:
			flipbookComponent->SetFlipbook(idle);
			flipbookComponent->SetLooping(false);
			break;
	    default:
			break;
	}

	// AI Sensing
	if (boomBoom != NULL && zipZap != NULL && currentState != State4::Dead)
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

		FVector location = GetActorLocation();
		location.Z += 30.f;
		location.Y -= 0.1f;
		AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, location, GetActorRotation());
		cfx->spriteChanger(2);
		currentState = State4::Dead;
	}
}

void AEnemy_Mouse::WalkLeft()
{
	if (stateUpdateTimer > 0.f)
	{
		stateUpdateTimer -= GetWorld()->GetDeltaSeconds();
		AddMovementInput(FVector(-1.f, 0.f, 0.f), 0.3f, false);
		rotation.Yaw = 180.f;
		flipbookComponent->SetWorldRotation(rotation);
	}
}

void AEnemy_Mouse::WalkRight()
{
	if (stateUpdateTimer > 0.f)
	{
		stateUpdateTimer -= GetWorld()->GetDeltaSeconds();
		AddMovementInput(FVector(1.f, 0.f, 0.f), 0.3f, false);
		rotation.Yaw = 0.f;
		flipbookComponent->SetWorldRotation(rotation);
	}
}

void AEnemy_Mouse::Attack()
{
	currentState = State4::Attacking;

	if (abs(playerToAttack->GetActorLocation().X - GetActorLocation().X) > MinimumDistanceToDealDamage && flipbookComponent->GetFlipbook() != attack)
	{
		if (flipbookComponent->GetFlipbook() != hurtAnim)
		{
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
		}
		GoToPlayer();
	}
	else if (abs(playerToAttack->GetActorLocation().X - GetActorLocation().X) < MinimumDistanceToDealDamage)
	{
		flipbookComponent->SetFlipbook(attack);
		flipbookComponent->SetLooping(false);

		if (flipbookComponent->GetPlaybackPositionInFrames() == 5 && hitAvailable)
		{
			hitAvailable = false;
			DealDamage();
		}

		if (flipbookComponent->GetPlaybackPositionInFrames() == 6)
		{
			hitAvailable = true;
		}

		if (flipbookComponent->GetPlaybackPositionInFrames() == 8 && hitAvailable)
		{
			hitAvailable = false;
			DealDamage();
		}
	}
}

void AEnemy_Mouse::RunAway()
{
}

void AEnemy_Mouse::GoToPlayer()
{
	// Face the player
	if (playerToAttack->GetActorLocation().X < GetActorLocation().X) // He's on the left
	{
		rotation.Yaw = 180.f;
		flipbookComponent->SetWorldRotation(rotation);
		AddMovementInput(FVector(-1.f, 0.f, 0.f), 0.3f, false);
	}
	else // He's on the right
	{
		rotation.Yaw = 0.f;
		flipbookComponent->SetWorldRotation(rotation);
		AddMovementInput(FVector(1.f, 0.f, 0.f), 0.3f, false);
	}
}

void AEnemy_Mouse::DealDamage()
{
	float distanceToBoomBoom = abs(boomBoom->GetActorLocation().X - GetActorLocation().X);
	float distanceToZipZap = abs(zipZap->GetActorLocation().X - GetActorLocation().X);

	if (playerToAttack->ActorHasTag("BoomBoom") && distanceToBoomBoom < MinimumDistanceToDealDamage)
	{
		boomBoom->setHealth(boomBoom->getHealth() - damage);
	}
	else if (playerToAttack->ActorHasTag("ZipZap") && distanceToZipZap < MinimumDistanceToDealDamage)
	{
		zipZap->setHealth(zipZap->getHealth() - damage);
	}
}

void AEnemy_Mouse::EndAttack()
{
	hitAvailable = true;

	if (flipbookComponent->GetFlipbook() == hurtAnim)
	{
		flipbookComponent->SetFlipbook(idle);
	}

	if (currentState != State4::Jumping && currentState != State4::Dead)
	{
		flipbookComponent->SetLooping(true);
		flipbookComponent->Play();
	}

	if (currentState == State4::Dead)
	{
		Destroy();
	}
}

void AEnemy_Mouse::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	currentState = State4::Idle;
	flipbookComponent->SetLooping(true);
	flipbookComponent->Play();
}