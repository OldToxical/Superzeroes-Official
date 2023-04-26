// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomBoom.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Toxic.h"
#include "Trash.h"
#include "Enemy.h"
#include "WindowTrigger.h"
#include "Button_But_Awesome.h"
#include "LAdder.h"
#include "Kismet/GameplayStatics.h"
#include "BoxTrigger.h"
#include "Button_But_Awesome.h"
#include "Enemy_Pigeon.h"
#include "ComicFX.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
ABoomBoom::ABoomBoom()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	ComboAttack_Savage_ExecutionTimer = SavageComboExecutionTime;
	attackInputTimer = 0.f;
	simpleAttack_sequenceTimeoutTimer = 0.f;
	jumpPreludeTimer = 0.f;
	punchPreludeTimer = 0.f;
	charMove = nullptr;
	characterState = State::Idle;
	jumping = nullptr;
	run = nullptr;
	simpleAttack = nullptr;
	simpleAttackSequence = nullptr;
	strongAttack = nullptr;
	strongAttackCharge = nullptr;
	zipZap = nullptr;
	isSimpleAttackSequenced = false;
	canClimb = false;
	launchZipZap = false;
	inputAvailable = true;
	canSpawnZipZap = false;
	stepMade = false;
	isUIparticleActive = false;
	health = 200.f;
	timeToHeal = 5.f;
	healRate = 0.5f;
	healing = false;
	respawnTime = 10.0f;
	meter = 0.0f;
	refillTime = 0.1f;
	skillCost = 50.f;
	currentLevel = 0;
	volume = 1.0f;

	if (flipbook)
	{
		flipbook->bOwnerNoSee = false;
		flipbook->bAffectDynamicIndirectLighting = true;
		flipbook->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		flipbook->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		flipbook->SetCollisionProfileName(CollisionProfileName);
		flipbook->SetGenerateOverlapEvents(false);
	}

	TimeBetweenWalkSounds = 16.0f;
	walkSoundTimer = TimeBetweenWalkSounds;
	toxicWalkSoundBool = false;
}

ABoomBoom::~ABoomBoom()
{
	flipbook = NULL;
	charMove = NULL;
	jumping = NULL;
	run = NULL;
	simpleAttack = NULL;
	strongAttack = NULL;
	strongAttackCharge = NULL;
	zipZap = NULL;

	Destroy();
}

void ABoomBoom::WriteFile(float scaleVal)
{
	/*FString path = FString(TEXT("C:/Users/Zlatko Radev/Desktop/start.txt"));
	if (!FFileHelper::SaveStringToFile(text, *path))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Failed To save");
		return;
	}*/

	//Cast<AEnemy_Pigeon>(UGameplayStatics::GetActorOfClass(GetWorld(), AEnemy_Pigeon::StaticClass()))->Attack();
}

void ABoomBoom::setHealth(float newHealth)
{
	if (characterState != State::Siege)
	{
		if (characterState != State::Hurt && characterState != State::Attacking && characterState != State::Combo_Savage && characterState != State::Siege && newHealth < health)
		{
			healTimer = 0.f;
			healing = false;
			characterState = State::Hurt;
			flipbook->SetFlipbook(hurt);
			flipbook->SetLooping(false);

			//hurt clip will play over and over without this
			if (!toxicDamage)
			{
				UGameplayStatics::PlaySound2D(GetWorld(), hurtSFX, volume);
			}

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(2.f, 0.3f, true, true, true, true);
		}

		health = newHealth;

		if (health >= 200.f)
		{
			health = 200.f;
		}
	}
}

// Called when the game starts or when spawned
void ABoomBoom::BeginPlay()
{
	Super::BeginPlay(); 

	toxicDamage = false;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABoomBoom::overlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ABoomBoom::overlapEnd);
	flipbook->SetFlipbook(idle);
	flipbook->OnFinishedPlaying.AddDynamic(this, &ABoomBoom::EndAttack);
	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();
	healTimer = 0.0f;
	deathTimer = 0.0f;

	FName tag = FName(TEXT("ZZ_Platform"));
	TSubclassOf<ABoxTrigger> subclass;
	subclass = ABoxTrigger::StaticClass();
	TArray<AActor*> actorsToIgnoreWhenMoving;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), subclass, tag, actorsToIgnoreWhenMoving);

	for (AActor* actorToIgnore : actorsToIgnoreWhenMoving)
	{
		GetCapsuleComponent()->IgnoreActorWhenMoving(actorToIgnore, true);
	}

	spawnLoc.Empty();
	spawnLoc.Add(FVector(0.f, .5f, -378.f));
	spawnLoc.Add(FVector(1058.f, .5f, -378.f));
	spawnLoc.Add(FVector(3043.f, .5f, -58.f));
	spawnLoc.Add(FVector(5028.f, .5f, -378.f));
	spawnLoc.Add(FVector(7050.f, .5f, 42.f));
	spawnLoc.Add(FVector(7120.f, .5f, 1005.f));
	spawnLoc.Add(FVector(7420.f, .5f, 1592.f));
	spawnLoc.Add(FVector(9410.f, .5f, 2092.f));
}

// Called every frame
void ABoomBoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (characterState != State::Siege)
	{
		setMeter(refillTime);

		if (meter >= (99.9f - refillTime) && meter <= 99.9f)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), meterFull, volume);
		}
	}

	if (characterState != State::Dead)
	{
		UpdateState();
		UpdateAnimation();
	
		if (toxicDamage == true)
		{
			setHealth(health - 0.03f); // This damages Boom Boom, but not as much as Zip Zap
		}
	
		if (characterState != State::Hurt)
		{
			healTimer += DeltaTime;

			if (healTimer >= timeToHeal && health < 200.0f)
			{
				healing = true;
				UGameplayStatics::PlaySound2D(GetWorld(), healthRecharge, volume);
				healTimer = 0.0f;
			}
		}
		else
		{
			healTimer = 0.0f;
			healing = false;
		}

		if (healing)
		{
			setHealth(health + healRate);
		}

		if (health <= 0.f)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), deathSFX, volume);
			characterState = State::Dead;
			flipbook->SetFlipbook(dead);
			flipbook->SetLooping(false);
		}
	}
	else
	{
		deathTimer += DeltaTime;

		if (deathTimer >= respawnTime)
		{
			GetCapsuleComponent()->SetCollisionProfileName(TEXT("MainCharacter")); // Enable collision when alive
			health = 200.0f;
			deathTimer = 0.0f;
			SetActorLocation(spawnLoc[currentLevel]); // Respawn at last known location
			characterState = State::Idle;
			flipbook->SetLooping(true);
			flipbook->Play();
		}
	}
}

void ABoomBoom::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	smokeParticle->ActivateSystem();
	UGameplayStatics::PlaySound2D(GetWorld(), landSFX, volume);
	UGameplayStatics::PlayWorldCameraShake(GetWorld(), cameraShakeLandBP, GetActorLocation(), 0.f, 2000.f, 1.f, false);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, 0.3f, true, true, true, true);
	characterState = State::Idle;
	flipbook->SetLooping(true);
	flipbook->Play();
}

// Called to bind functionality to input
void ABoomBoom::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Boom Boom has no input component"));
		return;
	}

	PlayerInputComponent->BindAxis("MoveBoomBoom", this, &ABoomBoom::move);
	PlayerInputComponent->BindAxis("AttackBoomBoom", this, &ABoomBoom::Attack);
	PlayerInputComponent->BindAxis("ClimbBoomBoom", this, &ABoomBoom::climb);
	PlayerInputComponent->BindAction("JumpBoomBoom", IE_Pressed, this, &ABoomBoom::ExecuteJump);
	PlayerInputComponent->BindAction("InitiateComboAttack_Projectile", IE_Pressed, this, &ABoomBoom::InitiateZipZapComboAttack_Projectile);

	canSpawnZipZap = true;
}

void ABoomBoom::UpdateState()
{
	charMove->MaxWalkSpeed = characterSpeed;

	// Execute the savage attack's function, if the character is in its state
	if (characterState == State::Combo_Savage)
	{
		UpdateComboAttack_Savage();
	}

	// Always decrease the timeout timer of the sequence of the simple attack
	if (simpleAttack_sequenceTimeoutTimer > 0.f)
	{
		simpleAttack_sequenceTimeoutTimer -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		isSimpleAttackSequenced = false;
	}

	// Always apply impact of the punch when the correct animation frame is being executed
	if (punchPreludeTimer > 0.f)
	{
		punchPreludeTimer -= GetWorld()->GetDeltaSeconds();
	}
	else if (punchPreludeTimer < 0.f)
	{
		float feedbackIntensity = 1.f;

		if (launchZipZap)
		{
			// Launch Zip Zap
			zipZap->InitiateComboAttack_Projectile(rotation.Yaw);
			launchZipZap = false;
			punchPreludeTimer = 0.f;
			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), zipZapImpact, FVector(zipZap->GetActorLocation().X, zipZap->GetActorLocation().Y + 30.f, zipZap->GetActorLocation().Z), FRotator(0, 0, 0), FVector(.8f, .8f, .8f));
		}
		else
		{
			// Apply damage
			punchPreludeTimer = 0.f;
			float damage = 25.f;

			if (flipbook->GetFlipbook() == strongAttack)
			{
				damage = 50.f;
				feedbackIntensity = 1.7f;
			}

			ProcessHit(damage);
		}

		UGameplayStatics::PlaySound2D(GetWorld(), attackSFX, volume);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(feedbackIntensity, .2f, true, true, true, true);
	}

	// Always decrease the jump prelude timer
	if (jumpPreludeTimer > 0.f)
	{
		jumpPreludeTimer -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		if (characterState == State::Jumping && !charMove->IsFalling())
		{
			int jumpnum = rand() % 4 + 1;

			switch (jumpnum)
			{
				case 1: UGameplayStatics::PlaySound2D(GetWorld(), jumpSFX, volume);
				case 2: UGameplayStatics::PlaySound2D(GetWorld(), jump2SFX, volume);
				case 3: UGameplayStatics::PlaySound2D(GetWorld(), jump3SFX, volume);
				case 4: UGameplayStatics::PlaySound2D(GetWorld(), jump4SFX, volume);
			}

			Jump();
			jumpPreludeTimer = 1.5f;
		}
	}

	// Handle UI Particle
	float proximityToZipZapX = abs(zipZap->GetActorLocation().X - GetActorLocation().X);
	float proximityToZipZapZ = abs(zipZap->GetActorLocation().Z - GetActorLocation().Z);

	if (proximityToZipZapX <= MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack && proximityToZipZapZ <= MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack && meter >= skillCost && !isUIparticleActive)
	{
		UIParticle->ActivateSystem(false);
		isUIparticleActive = true;
	}
	else if (proximityToZipZapX > MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack || proximityToZipZapZ > MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack || meter < skillCost)
	{
		UIParticle->DeactivateSystem();
		isUIparticleActive = false;
	}
}

void ABoomBoom::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State::Combo_Savage && characterState != State::Attacking && characterState != State::Jumping && characterState != State::Hurt && characterState != State::Siege)
		{
			characterState = State::Running;
			flipbook->SetFlipbook(run);
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State::Attacking && characterState != State::Combo_Savage && characterState != State::Jumping && characterState != State::Hurt && characterState != State::Siege)
		{
			characterState = State::Idle;
			flipbook->SetFlipbook(idle);
		}
	}
}

void ABoomBoom::move(float scaleVal)
{
	// Add movement force only if the character is not in a state of attacking
	if (characterState != State::Dead && inputAvailable)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && (characterState != State::Siege) && (attackInputTimer < StrongAttackMinimumInputTime))
		{
			characterSpeed = 200.f;
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);
		}

		// Determine the character's facing direction, regardless of the state
		if (scaleVal > 0.f && (characterState == State::Running || characterState == State::Combo_Savage))
		{
			if (flipbook->GetFlipbook() == run && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 1 || flipbook->GetPlaybackPositionInFrames() == 7) && !charMove->IsFalling())
			{
				if (toxicDamage)
				{
					switch (toxicWalkSoundBool)
					{
						case 0:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk1SFX, volume);
						case 1:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk2SFX, volume);
					}
					toxicWalkSoundBool = !toxicWalkSoundBool;
				}
				else
				{
					int walknum = rand() % 4 + 1;

					switch (walknum)
					{
						case 1: UGameplayStatics::PlaySound2D(GetWorld(), walkSFX, volume);
						case 2: UGameplayStatics::PlaySound2D(GetWorld(), walk2SFX, volume);
						case 3: UGameplayStatics::PlaySound2D(GetWorld(), walk3SFX, volume);
						case 4: UGameplayStatics::PlaySound2D(GetWorld(), walk4SFX, volume);
					}

					UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(.4f, .15f, true, true, true, true);
					smokeParticle->ActivateSystem();
				}
				stepMade = true;
			}

			if (flipbook->GetFlipbook() == run && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 8))
			{
				stepMade = false;
			}

			rotation.Yaw = 0.f;
			flipbook->SetWorldRotation(rotation);
		}
		else if (scaleVal < 0.f && (characterState == State::Running || characterState == State::Combo_Savage))
		{
			if (flipbook->GetFlipbook() == run && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 1 || flipbook->GetPlaybackPositionInFrames() == 7) && !charMove->IsFalling())
			{
				if (toxicDamage)
				{
					switch (toxicWalkSoundBool)
					{
						case 0:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk1SFX, volume);
						case 1:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk2SFX, volume);
					}
					toxicWalkSoundBool = !toxicWalkSoundBool;
				}
				else
				{
					int walknum = rand() % 4 + 1;

					switch (walknum)
					{
						case 1: UGameplayStatics::PlaySound2D(GetWorld(), walkSFX, volume);
						case 2: UGameplayStatics::PlaySound2D(GetWorld(), walk2SFX, volume);
						case 3: UGameplayStatics::PlaySound2D(GetWorld(), walk3SFX, volume);
						case 4: UGameplayStatics::PlaySound2D(GetWorld(), walk4SFX, volume);
					}

					UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(.4f, .15f, true, true, true, true);
					smokeParticle->ActivateSystem();
				}
				stepMade = true;
			}

			if (flipbook->GetFlipbook() == run && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 8))
			{
				stepMade = false;
			}

			rotation.Yaw = 180.0f;
			flipbook->SetWorldRotation(rotation);
		}
	}
}

void ABoomBoom::ExecuteJump()
{
	if (characterState != State::Dead && inputAvailable)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && !charMove->IsFalling() && (characterState != State::Hurt) && (characterState != State::Siege) && (characterState != State::Jumping) && (!canClimb))
		{
			jumpPreludeTimer = 0.3f;
			characterState = State::Jumping;
			flipbook->SetLooping(false);
			flipbook->SetFlipbook(jumping);
		}
	}
}

void ABoomBoom::climb(float scaleVal)
{
	if (characterState != State::Dead)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && characterState != State::Hurt && inputAvailable)
		{
			if (canClimb == true && characterState != State::Jumping)
			{
				if (scaleVal != 0)
				{
					charMove->MovementMode = (TEnumAsByte<EMovementMode>)3;
					charMove->Velocity = FVector(charMove->Velocity.X, 0, scaleVal * 200);
					charMove->GravityScale = 0.0f;
					charMove->MovementMode = (TEnumAsByte<EMovementMode>)5;
					charMove->Velocity.X = 0;
				}
				else
				{
					charMove->GravityScale = 1.0f;
					charMove->MovementMode = (TEnumAsByte<EMovementMode>)1;
				}
			}
		}
	}
}

void ABoomBoom::Attack(float scaleVal)
{
	if (characterState != State::Dead && inputAvailable)
	{
		// Allow the execution of the simple attack only if the character is not in a state of savage attack
		if (characterState != State::Combo_Savage && characterState != State::Siege && !charMove->IsFalling())
		{
			// If the attack button is pressed (or held), keep track of how long the user is holding the button down
			if (scaleVal > 0.f && simpleAttack_sequenceTimeoutTimer < (SimpleAttackSequenceTimeout - SimpleAttackAnimationLength))
			{
				// Increase the time the button has been held down
				attackInputTimer += GetWorld()->GetDeltaSeconds();

				// If the user is holding the button for too long, change the state of the character to "charging". From this point on, a strong attack will be executed once the button is released
				if (attackInputTimer > StrongAttackMinimumInputTime)
				{
					flipbook->SetFlipbook(strongAttackCharge);

					// Change the state to "attacking"
					characterState = State::Attacking;
				}
			}
			else // The button is not pressed. If the value of "attackInputTimer" is bigger than 0.f, this means the button was released during the current iteration, so let's determine what attack to execute
			{
				// Simple attack
				if (attackInputTimer > 0.f && attackInputTimer < StrongAttackMinimumInputTime)
				{
					// First attack
					if (simpleAttack_sequenceTimeoutTimer <= 0.f && !isSimpleAttackSequenced)
					{
						// Set the corresponding animation to execute and set the flipbook's property of looping to false, since we want the animation to execute only once
						flipbook->SetLooping(false);
						flipbook->SetFlipbook(simpleAttack);
						isSimpleAttackSequenced = true;
						punchPreludeTimer = AcutalPunchDelay;
						simpleAttack_sequenceTimeoutTimer = SimpleAttackSequenceTimeout;
						launchZipZap = false;

						// Change the state to "attacking"
						characterState = State::Attacking;
					}
					else if (simpleAttack_sequenceTimeoutTimer > 0.f && simpleAttack_sequenceTimeoutTimer < (SimpleAttackSequenceTimeout - SimpleAttackAnimationLength) && isSimpleAttackSequenced) // Second Attack
					{
						flipbook->SetLooping(false);
						flipbook->SetFlipbook(simpleAttackSequence);
						isSimpleAttackSequenced = false;
						punchPreludeTimer = AcutalPunchDelay / 2.5f;

						// Change the state to "attacking"
						characterState = State::Attacking;
					}
				}
				else if (attackInputTimer >= StrongAttackMinimumInputTime) // Strong attack
				{
					// Set the corresponding animation to execute and set the flipbook's property of looping to false, since we want the animation to execute only once
					flipbook->SetLooping(false);
					flipbook->SetFlipbook(strongAttack);
					punchPreludeTimer = AcutalPunchDelay + 0.264f;

					// Change the state to "attacking"
					characterState = State::Attacking;
				}

				// Reset the timer, doesn't matter if the button was released or wasn't pressed at all during this iteration, it's currently not pressed.
				attackInputTimer = 0.f;
			}
		}
	}
}

void ABoomBoom::EndAttack()
{
	// Once an attack animation has finished, reset the character's state to "idle" and his flipbook's looping property to true, since only the attack animations shouldn't loop
	
	if (characterState != State::Dead && characterState != State::Jumping)
	{
		characterState = State::Idle;
		flipbook->SetLooping(true);
		flipbook->Play();
	}
}

void ABoomBoom::InitiateComboAttack_Savage(float directionRotation)
{
	// Zip Zap has tased Boom Boom and he must start running like crazy in the direction Zip Zap was facing when he tased him
	rotation.Yaw = directionRotation;
	flipbook->SetWorldRotation(rotation);
	characterSpeed = 300.f;
	int growlNum = rand() % 4 + 1;

	switch (growlNum)
	{
		case 1: UGameplayStatics::PlaySound2D(GetWorld(), growlSFX, volume);
		case 2: UGameplayStatics::PlaySound2D(GetWorld(), growl2SFX, volume);
		case 3: UGameplayStatics::PlaySound2D(GetWorld(), growl3SFX, volume);
		case 4: UGameplayStatics::PlaySound2D(GetWorld(), growl4SFX, volume);
	}

	characterState = State::Combo_Savage;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, SavageComboExecutionTime, true, true, true, true);
}

void ABoomBoom::InitiateZipZapComboAttack_Projectile()
{
	if (zipZap != NULL && meter >= skillCost)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && !charMove->IsFalling() && (characterState != State::Siege) && inputAvailable)
		{
			float proximityToZipZapX = abs(zipZap->GetActorLocation().X - GetActorLocation().X);
			float proximityToZipZapZ = abs(zipZap->GetActorLocation().Z - GetActorLocation().Z);

			if (proximityToZipZapX <= MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack && proximityToZipZapZ <= MaximumDistanceBetweenPlayersForInitiatingProjectileComboAttack)
			{
				if (IsFacingZipZap())
				{
					punchPreludeTimer = AcutalPunchDelay;
					launchZipZap = true;
					flipbook->SetLooping(false);
					flipbook->SetFlipbook(simpleAttack);
					characterState = State::Attacking;
					setMeter(-skillCost);
				}
			}
		}
	}
}

bool ABoomBoom::IsFacingZipZap()
{
	// Zip Zap is on the left and Boom Boom is looking left
	if ((zipZap->GetActorLocation().X < GetActorLocation().X) && rotation.Yaw > 0.f)
	{
		return true;
	}
	else if ((zipZap->GetActorLocation().X < GetActorLocation().X) && rotation.Yaw <= 0.f) // Zip Zap is on the left and Boom Boom is looking right
	{
		return false;
	}
	else if ((zipZap->GetActorLocation().X > GetActorLocation().X) && rotation.Yaw > 0.f) // Zip Zap is on the right and Boom Boom is looking left
	{
		return false;
	}
	else if ((zipZap->GetActorLocation().X > GetActorLocation().X) && rotation.Yaw <= 0.f) // Zip Zap is on the right and Boom Boom is looking right
	{
		return true;
	}

	return false;
}

void ABoomBoom::UpdateComboAttack_Savage()
{
	// The length of the attack is finite, decrease the timer that keeps of this each iteration
	ComboAttack_Savage_ExecutionTimer -= GetWorld()->GetDeltaSeconds();
	flipbook->SetFlipbook(savageComboAttack);

	// There is still time to be executed
	if (ComboAttack_Savage_ExecutionTimer > 0.f)
	{
		if (flipbook->GetComponentRotation().Yaw < 180.f) // The user wants Boom Boom to run right
		{
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.f, false);
		}
		else // The user wants Boom Boom to run left
		{
			AddMovementInput(FVector(-1.0f, 0.0f, 0.0f), 1.f, false);
		}
	}
	else // There's no more time, end the savage attack
	{
		ComboAttack_Savage_ExecutionTimer = SavageComboExecutionTime;
		characterState = State::Idle;
	}
}

void ABoomBoom::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp && flipbook->GetFlipbook() != dead)
	{
		if (otherActor->IsA(AToxic::StaticClass()))
		{
			toxicDamage = true;
		}
		if (otherActor->IsA(ATrash::StaticClass()))
		{
			FVector loc = FVector(GetActorLocation().X, GetActorLocation().Y - 0.1f, GetActorLocation().Z + 40.f);
			AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, loc, GetActorRotation());
			cfx->spriteChanger(4);
			setHealth(health - 5.f);
		}
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			if (characterState == State::Combo_Savage)
			{
				if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
				{
					Enemy->TakeEnemyDamage(100.f);
					UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), enemyImpact, FVector(Enemy->GetActorLocation().X, Enemy->GetActorLocation().Y + 30.f, Enemy->GetActorLocation().Z), FRotator(0, 0, 0), FVector(.9f, .9f, .9f));
					UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, 0.2f, true, true, true, true);
				}
			}
		}
		if (otherActor->IsA(AWindowTrigger::StaticClass()))
		{
			if (characterState == State::Combo_Savage)
			{
				if (AWindowTrigger* window = Cast<AWindowTrigger>(otherActor))
				{
					window->BreakWindow();
					UGameplayStatics::PlaySound2D(GetWorld(), glassBreak, volume);
				}
			}
		}
		if (otherActor->IsA(ALAdder::StaticClass()))
		{
			canClimb = true;
		}
		if (otherActor->ActorHasTag("LevelRespawnTrigger"))
		{
			// Get trigger index
			int triggerNum = UKismetStringLibrary::Conv_StringToInt(otherActor->Tags[1].ToString());

			if (triggerNum == currentLevel)
			{
				Respawn();
			}
		}
	}
}

void ABoomBoom::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		if (otherActor->IsA(AToxic::StaticClass()))
		{
			toxicDamage = false;
		}

		if (otherActor->IsA(ALAdder::StaticClass()))
		{
			canClimb = false;
			charMove->GravityScale = 0.8f;
			charMove->MovementMode = (TEnumAsByte<EMovementMode>)1;
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("shart"));
		}
	}
}

void ABoomBoom::ProcessHit(float damage_)
{
	FHitResult OutHit;
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(zipZap);
	actorsToIgnore.Add(UGameplayStatics::GetActorOfClass(GetWorld(), ASiege::StaticClass()));
	FVector startPoint = GetActorLocation();
	FVector endPoint = FVector(startPoint.X, startPoint.Y, startPoint.Z - 2.5f);

	if (rotation.Yaw > 0.f) // Looking left
	{
		if (damage_ >= 50.f)
		{
			endPoint.X -= 200.f;
		}
		else
		{
			endPoint.X -= 150.f;
		}
	}
	else // Looking right
	{
		if (damage_ >= 50.f)
		{
			endPoint.X += 200.f;
		}
		else
		{
			endPoint.X += 150.f;
		}
	}

	bool hit = UKismetSystemLibrary::LineTraceSingle(this, startPoint, endPoint, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::None, OutHit, true);
	if (hit)
	{
		FRotator rot = OutHit.GetActor()->GetActorRotation();
		AActor* HitActor = OutHit.GetActor();

		if (AEnemy* Enemy = Cast<AEnemy>(HitActor))
		{
			FVector impactForce = FVector(500.f, 0.f, 180.f);
			if (rotation.Yaw > 0) // Looking left
			{
				impactForce.X *= -1.f;
			}
			
			if (flipbook->GetFlipbook() == simpleAttackSequence || flipbook->GetFlipbook() == strongAttack)
			{
				Enemy->LaunchCharacter(impactForce, false, false);
			}

			AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(comicFX, FVector(endPoint.X, endPoint.Y - 0.1f, endPoint.Z + 100.f), GetActorRotation());
			cfx->spriteChanger(3);
			Enemy->TakeEnemyDamage(damage_);
			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), enemyImpact, FVector(Enemy->GetActorLocation().X, Enemy->GetActorLocation().Y + 30.f, Enemy->GetActorLocation().Z), FRotator(0, 0, 0), FVector(.7f, .7f, .7f));

			if (damage_ >= 50.f)
			{
				UGameplayStatics::PlayWorldCameraShake(GetWorld(), cameraShakeHitBP, GetActorLocation(), 0.f, 2000.f, 1.f, false);
			}

			return;
		}

		if (AButton_But_Awesome* button = Cast<AButton_But_Awesome>(HitActor))
		{
			button->ButtPress();
		}

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), smokeParticle->GetAsset(), endPoint, FRotator(0.f, 0.f, 0.f), FVector(5.f, 5.f, 5.f));
	}
}