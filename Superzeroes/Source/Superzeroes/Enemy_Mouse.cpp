// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy_Mouse.h"
#include "Components/BoxComponent.h"
#include "ComicFX.h"
#include "LevelManager.h"
#include "Trash.h"
#include <chrono>
#include <thread>
#include "Kismet/KismetStringLibrary.h"

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
	chooseActionTimeoutTimer = FMath::RandRange(1, 6);
	stateUpdateTimer = 0.f;
	speed = 0.f;
	damage = 50.f;
	TimeBetweenWalkSounds = 5.0f;
	healthPoints = 125.f;
	hitAvailable = true;
	inCombat = false;
	deathFXcompleted = false;
	isColliding = false;
}

void AEnemy_Mouse::AI()
{
	ChooseAction();
	UpdateState();
}

void AEnemy_Mouse::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_Mouse::OverlapBegin);
	TimeBetweenWalkSounds = 5.0f;
	walkSoundTimer = TimeBetweenWalkSounds;
}

void AEnemy_Mouse::Tick(float DeltaTime)
{
	if (zipZap == nullptr || boomBoom == nullptr)
	{
		boomBoom = Cast<ABoomBoom>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass()));
		zipZap = Cast<AZipZap>(UGameplayStatics::GetActorOfClass(GetWorld(), AZipZap::StaticClass()));
	}

	AI();
}

void AEnemy_Mouse::TakeEnemyDamage(float damage_)
{
	if (flipbookComponent->GetFlipbook() != hurtAnim && currentState != State4::Dead && currentState != State4::Jumping)
	{
		healthPoints -= damage_;
		flipbookComponent->SetFlipbook(hurtAnim);
		flipbookComponent->SetLooping(false);
	}
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

	if (isColliding)
	{
		isColliding = false;
		return;
	}

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
		chooseActionTimeoutTimer = (2 * healthPoints) / 100.f;
	}
	else if (currentAction == Action::Jump)
	{
		currentState = State4::Jumping;
		chooseActionTimeoutTimer = (2 * (characterMovementComponent->JumpZVelocity)) / 980.f;
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
	SetActorLocation(FVector(GetActorLocation().X, .505f, GetActorLocation().Z));

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
			if (flipbookComponent->GetFlipbook() != hurtAnim && flipbookComponent->GetFlipbook() != jumpAnim && !characterMovementComponent->IsFalling())
			{
				flipbookComponent->SetFlipbook(jumpAnim);
				flipbookComponent->SetLooping(false);
				UGameplayStatics::PlaySound2D(GetWorld(), jumpSFX);
				Jump();
			}
			break;
		case State4::WalkingLeft:
			if (flipbookComponent->GetFlipbook() != hurtAnim && flipbookComponent->GetFlipbook() != jumpAnim)
			{
				flipbookComponent->SetFlipbook(walk);
				flipbookComponent->SetLooping(true);
			}
			WalkLeft();
			break;
		case State4::WalkingRight:
			if (flipbookComponent->GetFlipbook() != hurtAnim && flipbookComponent->GetFlipbook() != jumpAnim)
			{
				flipbookComponent->SetFlipbook(walk);
				flipbookComponent->SetLooping(true);
			}
			WalkRight();
			break;
		case State4::Dead:
			flipbookComponent->SetFlipbook(dead);
			flipbookComponent->SetLooping(false);

			if ((flipbookComponent->GetFlipbook() == dead && flipbookComponent->GetPlaybackPositionInFrames() == 11) || (flipbookComponent->GetFlipbook() == hurtAnim && flipbookComponent->GetPlaybackPositionInFrames() == 2))
			{
				Cast<ALevelManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManager::StaticClass()))->RemoveEnemy(this);
				Destroy();
			}
			break;
	    default:
			break;
	}

	// AI Sensing
	if (boomBoom != NULL && zipZap != NULL && currentState != State4::Dead)
	{
		if (zipZap->GetState() == ZZ_State::Dead)
		{
			playerToAttack = boomBoom;
		}

		if (boomBoom->GetState() == BB_State::Dead)
		{
			playerToAttack = zipZap;
		}

		if (zipZap->GetState() == ZZ_State::Dead && boomBoom->GetState() == BB_State::Dead)
		{
			inCombat = false;
		}

		if ((abs(GetActorLocation().X - boomBoom->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - boomBoom->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ) && boomBoom->GetState() != BB_State::Dead)
		{
			inCombat = true;
			playerToAttack = boomBoom;
		}

		if ((abs(GetActorLocation().X - zipZap->GetActorLocation().X) < MinimumDistanceToGetIntoCombatX) && (abs(GetActorLocation().Z - zipZap->GetActorLocation().Z) < MinimumDistanceToGetIntoCombatZ) && zipZap->GetState() != ZZ_State::Dead)
		{
			inCombat = true;
			playerToAttack = zipZap;
		}
	}

	// Check Health
	if (healthPoints <= 0.f)
	{
		if (IsValid(spawner))
		{
			spawner->RemoveEnemy(this);
		}

		if (!deathFXcompleted)
		{
			FVector location = GetActorLocation();
			location.Z += 30.f;
			location.Y -= 0.1f;
			AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, location, GetActorRotation());
			cfx->spriteChanger(2);
			UGameplayStatics::PlaySound2D(GetWorld(), deathSFX);
			deathFXcompleted = true;
		}
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
		walkSoundTimer += 0.1f;

		if (walkSoundTimer >= TimeBetweenWalkSounds)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), walkSFX);
			walkSoundTimer = 0.0f;
		}
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
		walkSoundTimer += 0.1f;

		if (walkSoundTimer >= TimeBetweenWalkSounds)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), walkSFX);
			walkSoundTimer = 0.0f;
		}
	}
}

void AEnemy_Mouse::Attack()
{
	currentState = State4::Attacking;

	if (IsValid(playerToAttack))
	{
		if (abs(playerToAttack->GetActorLocation().X - GetActorLocation().X) > MinimumDistanceToDealDamage && flipbookComponent->GetFlipbook() != attack)
		{
			if (flipbookComponent->GetFlipbook() != hurtAnim)
			{
				flipbookComponent->SetFlipbook(walk);
				flipbookComponent->SetLooping(true);
			}
			GoToPlayer();
		}
		else if (abs(playerToAttack->GetActorLocation().X - GetActorLocation().X) < MinimumDistanceToDealDamage && abs(playerToAttack->GetActorLocation().Z - GetActorLocation().Z) < MinimumDistanceToDealDamage)
		{
			flipbookComponent->SetFlipbook(attack);
			flipbookComponent->SetLooping(false);

			if (flipbookComponent->GetPlaybackPositionInFrames() == 5 && hitAvailable)
			{
				hitAvailable = false;
				int attackSFX = rand() % 5 + 1;
				switch (attackSFX)
				{
					case 1: UGameplayStatics::PlaySound2D(GetWorld(), attack1SFX);
					case 2: UGameplayStatics::PlaySound2D(GetWorld(), attack2SFX);
					case 3:	UGameplayStatics::PlaySound2D(GetWorld(), attack3SFX);
					case 4:	UGameplayStatics::PlaySound2D(GetWorld(), attack4SFX);
					case 5:	UGameplayStatics::PlaySound2D(GetWorld(), attack5SFX);
					case 6:	UGameplayStatics::PlaySound2D(GetWorld(), attack6SFX);
				}
				DealDamage();
			}

			if (flipbookComponent->GetPlaybackPositionInFrames() == 6)
			{
				hitAvailable = true;
			}

			if (flipbookComponent->GetPlaybackPositionInFrames() == 8 && hitAvailable)
			{
				hitAvailable = false;
				int attackSFX = rand() % 5 + 1;
				switch (attackSFX)
				{
					case 1: UGameplayStatics::PlaySound2D(GetWorld(), attack1SFX);
					case 2: UGameplayStatics::PlaySound2D(GetWorld(), attack2SFX);
					case 3:	UGameplayStatics::PlaySound2D(GetWorld(), attack3SFX);
					case 4:	UGameplayStatics::PlaySound2D(GetWorld(), attack4SFX);
					case 5:	UGameplayStatics::PlaySound2D(GetWorld(), attack5SFX);
					case 6:	UGameplayStatics::PlaySound2D(GetWorld(), attack6SFX);
				}
				DealDamage();
			}
		}
	}
}

void AEnemy_Mouse::GoToPlayer()
{
	if (IsValid(playerToAttack))
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
}

void AEnemy_Mouse::DealDamage()
{
	float distanceToBoomBoom = abs(boomBoom->GetActorLocation().X - GetActorLocation().X);
	float distanceToZipZap = abs(zipZap->GetActorLocation().X - GetActorLocation().X);

	if (IsValid(playerToAttack))
	{
		if (playerToAttack->ActorHasTag("BoomBoom") && distanceToBoomBoom < MinimumDistanceToDealDamage)
		{
			boomBoom->setHealth(boomBoom->getHealth() - damage);			
			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, FVector(boomBoom->GetActorLocation().X, boomBoom->GetActorLocation().Y + 30.f, boomBoom->GetActorLocation().Z), FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
		}
		else if (playerToAttack->ActorHasTag("ZipZap") && distanceToZipZap < MinimumDistanceToDealDamage)
		{
			zipZap->setHealth(zipZap->getHealth() - damage);

			if (zipZap->GetState() != ZZ_State::Siege)
			{
				UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), zipZapImpact, FVector(zipZap->GetActorLocation().X, zipZap->GetActorLocation().Y + 30.f, zipZap->GetActorLocation().Z), FRotator(0, 0, 0), FVector(.6f, .6f, .6f));
				return;
			}

			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, FVector(zipZap->GetActorLocation().X, zipZap->GetActorLocation().Y + 30.f, zipZap->GetActorLocation().Z), FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
		}
	}
}

void AEnemy_Mouse::OverlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor->ActorHasTag("LevelRespawnTrigger"))
	{
		Cast<ALevelManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManager::StaticClass()))->RemoveEnemy(this);
		Destroy();
	}

	if (currentState != State4::Dead && currentState != State4::Jumping && !otherActor->IsA(AEnemy::StaticClass()) && flipbookComponent->GetFlipbook() != hurtAnim)
	{
		isColliding = true;
		chooseActionTimeoutTimer = 5.f;

		if (currentState == State4::WalkingLeft)
		{
			currentAction = Action::WalkRight;
		}
		else if (currentState == State4::WalkingRight)
		{
			currentAction = Action::WalkLeft;
		}

		if (otherActor->IsA(ABoomBoom::StaticClass()) || otherActor->IsA(AZipZap::StaticClass()))
		{
			inCombat = true;
		}

		if (otherActor->IsA(ATrash::StaticClass()))
		{
			GetCapsuleComponent()->IgnoreActorWhenMoving(otherActor, true);
		}

		ExecuteAction();
	}
}

void AEnemy_Mouse::OverlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	isColliding = false;
}

void AEnemy_Mouse::EndAttack()
{
	hitAvailable = true;

	if (flipbookComponent->GetFlipbook() == hurtAnim)
	{
		flipbookComponent->SetFlipbook(idle);

		if (characterMovementComponent->IsFalling())
		{
			flipbookComponent->SetLooping(true);
			flipbookComponent->Play();
		}
	}

	if (currentState != State4::Jumping && currentState != State4::Dead)
	{
		flipbookComponent->SetFlipbook(idle);
		flipbookComponent->SetLooping(true);
		flipbookComponent->Play();
	}

	if (currentState == State4::Dead)
	{
		Cast<ALevelManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManager::StaticClass()))->RemoveEnemy(this);
		Destroy();
	}
}

void AEnemy_Mouse::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if (currentState != State4::Dead && flipbookComponent->GetFlipbook() != hurtAnim)
	{
		currentState = State4::Idle;
		flipbookComponent->SetFlipbook(idle);
		flipbookComponent->SetLooping(true);
		flipbookComponent->Play();
	}

	if (currentState == State4::Dead)
	{
		flipbookComponent->SetFlipbook(dead);
		flipbookComponent->SetLooping(false);
		flipbookComponent->Play();
	}
}