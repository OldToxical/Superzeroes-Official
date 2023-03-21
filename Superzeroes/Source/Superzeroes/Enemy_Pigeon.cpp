// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Pigeon.h"
#include "Components/BoxComponent.h"
#include "Projectile.h"
#include <chrono>
#include <thread>
#include "ComicFX.h"

AEnemy_Pigeon::AEnemy_Pigeon()
{
	srand(time(NULL));

	TArray<float, TFixedAllocator<6>> actionsAfterJumping;
	actionsAfterJumping.Add(35.f); // Go Idle
	actionsAfterJumping.Add(34.f); // Jump
	actionsAfterJumping.Add(50.f); // Walk Left
	actionsAfterJumping.Add(38.f); // Walk Right
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
	inCombat = false;

	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));
	hitbox->SetRelativeLocation(FVector(8.0, 0.0, 0.0));
	hitbox->SetupAttachment(RootComponent);

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	collision->SetupAttachment(RootComponent);
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
	float reward = rand() % 10 + 5;
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
		    flipbookComponent->SetFlipbook(idle);
			flipbookComponent->SetLooping(true);
			break;
		case State3::Jumping:
			flipbookComponent->SetFlipbook(jumpAnim);
			flipbookComponent->SetLooping(false);
			Jump();
			break;
		case State3::WalkingLeft:
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
			WalkLeft();
			break;
		case State3::WalkingRight:
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
			WalkRight();
			break;
		case State3::Attacking:
			flipbookComponent->SetFlipbook(attack);
			flipbookComponent->SetLooping(false);
			Attack();
			break;
		case State3::RunningAway:
			flipbookComponent->SetFlipbook(walk);
			flipbookComponent->SetLooping(true);
			break;
	    default:
			break;
	}

	// AI Sensing
	if (boomBoom != nullptr && zipZap != nullptr)
	{
		/*if ((abs(GetActorLocation().X - boomBoom->GetActorLocation().X) < MinimumDistanceToGetIntoCombat) || (abs(GetActorLocation().X - zipZap->GetActorLocation().X) < MinimumDistanceToGetIntoCombat))
		{
			inCombat = true;
		}*/
		if ((abs(GetActorLocation().X - boomBoom->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - boomBoom->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ) && (!inCombat))
		{
			inCombat = true;
			playerToAttack = boomBoom;
		}

		if ((abs(GetActorLocation().X - zipZap->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - zipZap->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ) && (!inCombat))
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

		//UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), muzzleFlashParticle, muzzleFlashLocation);

		// Spawn bullet
		AProjectile* bullet = GetWorld()->SpawnActor<AProjectile>(bulletClass, muzzleFlashLocation, bulletLookAtVector);
	}
}

void AEnemy_Pigeon::RunAway()
{
}

void AEnemy_Pigeon::FaceNearestPlayer()
{
	// Boom Boom is closer
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
	}
	else // Zip Zap is closer
	{
		// Face him
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
}

void AEnemy_Pigeon::EndAttack()
{
	flipbookComponent->SetLooping(true);
	flipbookComponent->Play();

	//characterState = State::Idle;
}

void AEnemy_Pigeon::ProcessBulletCollision(FVector hitPos)
{
	FHitResult OutHit;
	FVector endPoint = hitPos;

	if (rotation.Yaw < 180.f) // Looking left
	{
		endPoint.X -= 40.f;
	}
	else // Looking right
	{
		endPoint.X += 40.f;
	}

	bool hit = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), hitPos, endPoint, 10.f, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::None, OutHit, true);
	if (hit)
	{
		FRotator rot = OutHit.GetActor()->GetActorRotation();
		AActor* HitActor = OutHit.GetActor();
		
		if (HitActor->ActorHasTag("BoomBoom"))
		{
			if (boomBoom != NULL)
			{
				boomBoom->setHealth(boomBoom->getHealth() - damage);
			}
		}
		
		if (HitActor->ActorHasTag("ZipZap"))
		{
			if (zipZap != NULL)
			{
				zipZap->setHealth(zipZap->getHealth() - damage);
			}
		}
	}
}