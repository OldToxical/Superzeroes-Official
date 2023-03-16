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

	siegeMode = nullptr;

	isSimpleAttackSequenced = false;
	launchZipZap = false;
	canClimb = false;
	health = 200.f;
	currentLevel = 0;

	spawnLoc.Add(FVector(-1800.f, .5f, -182.f));
	spawnLoc.Add(FVector(-300.f, .5f, -182.f));
	spawnLoc.Add(FVector(1400.f, .5f, -182.f));

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

void ABoomBoom::setHealth(float newHealth)
{
	if (characterState != State::Siege)
	{
		health = newHealth;

		if (characterState != State::Hurt && characterState != State::Attacking && characterState != State::Combo_Savage)
		{
			characterState = State::Hurt;
			flipbook->SetFlipbook(hurt);
			flipbook->SetLooping(false);
		}
	}
}

// Called when the game starts or when spawned
void ABoomBoom::BeginPlay()
{
	Super::BeginPlay(); 
	toxicDamage = false;
	SetupPlayerInputComponent(Super::InputComponent);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABoomBoom::overlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ABoomBoom::overlapEnd);


	//collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));


	flipbook->SetFlipbook(idle);
	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();
	healTimer = 0.0f;
	deathTimer = 0.0f;



	if (zipZap != nullptr)

	{
		zipZap->SetBoomBoomReference(this);
		zipZap->SetupPlayerInput(Super::InputComponent);
	}

	if (siegeMode)
	{
		siegeMode->SetupPlayerInput(Super::InputComponent);
	}
}

// Called every frame
void ABoomBoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (characterState != State::Dead)
	{
		UpdateState();
		UpdateAnimation();
	
		if (toxicDamage == true)
		{
			setHealth(health - 0.03f); //this damages Boom Boom, but not as much as Zip Zap
		}
	
		if (characterState == State::Idle)
		{
			healTimer += DeltaTime;
			if (healTimer >= 10.f)
			{
				setHealth(health + 0.5f);
			}
		}
		else
		{
			healTimer = 0.0f;
		}

		if (health <= 0.f)
		{
			GetCapsuleComponent()->SetCollisionProfileName(TEXT("Spectator"));
			characterState = State::Dead;
			flipbook->SetFlipbook(dead);
			flipbook->SetLooping(false);
		}
	}
	else
	{
		deathTimer += DeltaTime;
		if (deathTimer >= 15.0f) {
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

// Called to bind functionality to input
void ABoomBoom::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveBoomBoom", this, &ABoomBoom::move);
	PlayerInputComponent->BindAxis("AttackBoomBoom", this, &ABoomBoom::Attack);
	PlayerInputComponent->BindAxis("ClimbBoomBoom", this, &ABoomBoom::climb);
	PlayerInputComponent->BindAction("JumpBoomBoom", IE_Pressed, this, &ABoomBoom::ExecuteJump);
	PlayerInputComponent->BindAction("InitiateComboAttack_Projectile", IE_Pressed, this, &ABoomBoom::InitiateZipZapComboAttack_Projectile);
}

void ABoomBoom::UpdateState()
{
	//charMove->MaxWalkSpeed = characterSpeed;

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
		if (launchZipZap)
		{
			zipZap->InitiateComboAttack_Projectile(rotation.Yaw);
			launchZipZap = false;
			punchPreludeTimer = 0.f;
		}
		else
		{
			// Apply damage (will be implemented at a later stage)
			punchPreludeTimer = 0.f;
		}

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
			Jump();
			jumpPreludeTimer = 1.5f;
		}
	}
}

void ABoomBoom::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State::Combo_Savage && characterState != State::Attacking && characterState != State::Jumping && characterState != State::Hurt)
		{
			characterState = State::Running;
			flipbook->SetFlipbook(run);
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State::Attacking && characterState != State::Combo_Savage && characterState != State::Jumping && characterState != State::Hurt)
		{
			characterState = State::Idle;
			flipbook->SetFlipbook(idle);
		}
	}
}

void ABoomBoom::move(float scaleVal)
{
	// Add movement force only if the character is not in a state of attacking
	if (characterState != State::Dead)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && (characterState != State::Siege))
		{
			characterSpeed = 300.f;
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);
		}

		// Determine the character's facing direction, regardless of the state
		if (scaleVal > 0.f)
		{
			rotation.Yaw = 0.f;
			flipbook->SetWorldRotation(rotation);
		}
		else if (scaleVal < 0.f)
		{
			rotation.Yaw = 180.0f;
			flipbook->SetWorldRotation(rotation);
		}
	}
}

void ABoomBoom::ExecuteJump()
{
	if (characterState != State::Dead)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && !charMove->IsFalling() && characterState != State::Hurt && (characterState != State::Siege))
		{
			{
				jumpPreludeTimer = 0.47f;
				characterState = State::Jumping;
				flipbook->SetLooping(false);
				flipbook->SetFlipbook(jumping);
			}
		}
	}
}

void ABoomBoom::climb(float scaleVal)
{
	if (characterState != State::Dead)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && characterState != State::Hurt)
		{
			if (canClimb == true )
			{

				charMove->GravityScale = 0.0f;
				SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + scaleVal));
				if (scaleVal != 0)
				{
					charMove->MovementMode = (TEnumAsByte<EMovementMode>)3;
					charMove->Velocity.X = 0;
				}
			}
		}
	}
}

void ABoomBoom::Attack(float scaleVal)
{
	if (characterState != State::Dead)
	{
		// Allow the execution of the simple attack only if the character is not in a state of savage attack
		if (characterState != State::Combo_Savage && characterState != State::Siege)
		{
			// If the attack button is pressed (or held), keep track of how long the user is holding the button down
			if (scaleVal > 0.f && simpleAttack_sequenceTimeoutTimer < (SimpleAttackSequenceTimeout - SimpleAttackAnimationLength))
			{
				// Whatever the length is, change the state to "attacking"
				characterState = State::Attacking;

				// Increase the time the button has been held down
				attackInputTimer += GetWorld()->GetDeltaSeconds();

				// If the user is holding the button for too long, change the state of the character to "charging". From this point on, a strong attack will be executed once the button is released
				if (attackInputTimer > StrongAttackMinimumInputTime)
				{
					flipbook->SetFlipbook(strongAttackCharge);
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
						launchZipZap = false;
						ProcessHit(25.f);
					}
					else if (simpleAttack_sequenceTimeoutTimer > 0.f && simpleAttack_sequenceTimeoutTimer < (SimpleAttackSequenceTimeout - SimpleAttackAnimationLength) && isSimpleAttackSequenced) // Second Attack
					{
						flipbook->SetLooping(false);
						flipbook->SetFlipbook(simpleAttackSequence);
						isSimpleAttackSequenced = false;
						ProcessHit(25.f);
					}

					// Regardless whether the attack was executed for the first time or second, 
					simpleAttack_sequenceTimeoutTimer = SimpleAttackSequenceTimeout;
				}
				else if (attackInputTimer >= StrongAttackMinimumInputTime) // Strong attack
				{
					// Set the corresponding animation to execute and set the flipbook's property of looping to false, since we want the animation to execute only once
					flipbook->SetLooping(false);
					flipbook->SetFlipbook(strongAttack);
					ProcessHit(50.f);
				}
				else if (simpleAttack_sequenceTimeoutTimer <= 0.f && characterState == State::Attacking)
				{
					//EndAttack(); <----- for later to be fixed
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
	
	if (flipbook->GetFlipbook() != dead)
	{
		characterState = State::Idle;
		flipbook->SetLooping(true);
		flipbook->Play();

		//if (characterState == State::Jumping)
	//	{
		//	smokeParticle->ActivateSystem();
		//}

	}
}

void ABoomBoom::InitiateComboAttack_Savage(float directionRotation)
{
	// Zip Zap has tased Boom Boom and he must start running like crazy in the direction Zip Zap was facing when he tased him
	rotation.Yaw = directionRotation;
	flipbook->SetWorldRotation(rotation);
	characterSpeed = 450.f;
	characterState = State::Combo_Savage;
}

void ABoomBoom::InitiateZipZapComboAttack_Projectile()
{
	if (zipZap != NULL)
	{
		if ((characterState != State::Combo_Savage) && (characterState != State::Attacking) && !charMove->IsFalling() && (characterState != State::Siege))
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
			setHealth(health - 5.f);
		}
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			if (characterState == State::Combo_Savage)
			{
				if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
				{
					Enemy->TakeEnemyDamage(100.f);
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
				}
			}
		}
		if (otherActor->IsA(ALAdder::StaticClass()))
		{
			canClimb = true;
		}

		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, otherActor->GetName());
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
	FVector startPoint = GetActorLocation();
	FVector endPoint = FVector(startPoint.X, startPoint.Y, startPoint.Z - 5.f);

	if (rotation.Yaw > 0.f) // Looking left
	{
		endPoint.X -= 50.f;
	}
	else // Looking right
	{
		endPoint.X += 50.f;
	}

	bool hit = UKismetSystemLibrary::LineTraceSingle(this, startPoint, endPoint, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::Persistent, OutHit, true);
	if (hit)
	{
		FRotator rot = OutHit.GetActor()->GetActorRotation();
		AActor* HitActor = OutHit.GetActor();

		if (AEnemy* Enemy = Cast<AEnemy>(HitActor))
		{
			Enemy->TakeEnemyDamage(damage_);
		}
		if (HitActor->ActorHasTag("Button"))
		{
			AButton_But_Awesome* button  = (AButton_But_Awesome*)HitActor;

			if (button == NULL)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("null"));
				return;
			}
			button->ButtPress();
			
		}
	}
}