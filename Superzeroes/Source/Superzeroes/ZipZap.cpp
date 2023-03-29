// Fill out your copyright notice in the Description page of Project Settings.


#include "ZipZap.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "BoomBoom.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Toxic.h"
#include "Trash.h"
#include "Enemy.h"
#include "LAdder.h"
#include "ComicFX.h"
#include "BoxTriggerBoomBoom.h"
#include "Button_But_Awesome.h"
#include "Siege.h"
#include "Projectile.h"

// Sets default values
AZipZap::AZipZap()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	jumpPreludeTimer = 0.f;
	health = 100.f;
	meter = 0.0f;
	refillTime = 0.1f;
	skillCost = 50.f;
	currentLevel = 0;
	isElectrified = false;
	isShooting = false;
	toxicDamage = false;
	damageDealt = false;
	savageInitiated = false;
	inputAvailable = true;
	canClimb = false;

	flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
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

	spawnLoc.Add(FVector(-2740.f, .5f, -35.f));
	spawnLoc.Add(FVector(-1050.f, .5f, -35.f));
	spawnLoc.Add(FVector(600.f, .5f, 300.f));
	spawnLoc.Add(FVector(2160.f, .5f, -35.f));
	spawnLoc.Add(FVector(3760.f, .5f, -35.f));
}

void AZipZap::setHealth(float newHealth)
{
	if (characterState != State2::Siege)
	{
		if (characterState != State2::Hurt && characterState != State2::Attacking && characterState != State2::Combo_Projectile && newHealth < health)
		{
			characterState = State2::Hurt;
			flipbook->SetFlipbook(hurt);
			flipbook->SetLooping(false);
		}

		health = newHealth;

		if (health >= 100.f)
		{
			health = 100.f;
		}
	}
}

// Called when the game starts or when spawned
void AZipZap::BeginPlay()
{
	Super::BeginPlay();

	flipbook->SetFlipbook(idle);
	flipbook->OnFinishedPlaying.AddDynamic(this, &AZipZap::EndAttack);
	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();
	healTimer = 0.0f;
	deathTimer = 0.0f;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AZipZap::overlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AZipZap::overlapEnd);

	FName tag = FName(TEXT("BB_Platform"));
	TSubclassOf<ABoxTriggerBoomBoom> subclass;
	subclass = ABoxTriggerBoomBoom::StaticClass();
	TArray<AActor*> actorsToIgnoreWhenMoving;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), subclass, tag, actorsToIgnoreWhenMoving);

	for (AActor* actorToIgnore : actorsToIgnoreWhenMoving)
	{
		GetCapsuleComponent()->IgnoreActorWhenMoving(actorToIgnore, true);
	}
}

// Called every frame
void AZipZap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	setMeter(refillTime);

	if (characterState != State2::Dead)
	{
		UpdateAnimation();
		UpdateState();

		if (toxicDamage == true)
		{
			setHealth(health - 0.5f); // This damages Zip Zap far more than Boom Boom
		}
		if (characterState == State2::Idle)
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
			//GetCapsuleComponent()->SetCollisionProfileName(TEXT("Spectator")); // Disable collision while dead
			characterState = State2::Dead;
			flipbook->SetFlipbook(dead);
			flipbook->SetLooping(false);
		}
	}
	else
	{
		deathTimer += DeltaTime;

		if (deathTimer >= 15.0f) // When 15 seconds have passed
		{
			GetCapsuleComponent()->SetCollisionProfileName(TEXT("MainCharacter")); // Enable collision for zip zap when respawning
			health = 100.0f;
			deathTimer = 0.0f;
			SetActorLocation(spawnLoc[currentLevel]);
			characterState = State2::Idle;
			flipbook->SetLooping(true);
			flipbook->Play();
		}
	}
}

void AZipZap::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if (characterState == State2::Combo_Projectile)
	{
		charMove->GravityScale = 1.f;
		isElectrified = false;
	}

	characterState = State2::Idle;
	flipbook->SetLooping(true);
	flipbook->Play();
}

void AZipZap::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping && characterState != State2::Hurt)
		{
			characterState = State2::Running;
			flipbook->SetFlipbook(run);
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping && characterState != State2::Hurt)
		{
			characterState = State2::Idle;
			flipbook->SetFlipbook(idle);
		}
	}
}

void AZipZap::move(float scaleVal)
{
	// Add movement force only if the character is not in a state of savage attack
	if (characterState != State2::Dead)
	{
		if (characterState != State2::Combo_Projectile && characterState != State2::Siege && inputAvailable)
		{
			characterSpeed = 500.f;
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);

			// Handle rotation
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
}

void AZipZap::InitiateComboAttack_Savage()
{
	if (boomBoom != nullptr && meter >= skillCost)
	{
		if (characterState != State2::Dead)
		{
			if (characterState != State2::Siege && characterState != State2::Attacking && characterState != State2::Combo_Projectile && boomBoom->GetState() != State::Combo_Savage && inputAvailable)
			{
				float proximityToBoomBoom = abs(boomBoom->GetActorLocation().X - GetActorLocation().X);

				if (proximityToBoomBoom <= MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack)
				{
					if (IsFacingBoomBoom())
					{
						characterState = State2::Attacking;
						flipbook->SetFlipbook(initiateBoomBoomSavageComboAttack);
						flipbook->SetLooping(false);
						setMeter(-skillCost);
					}
				}
			}
		}
	}
}

void AZipZap::InitiateComboAttack_Projectile(float directionRotation)
{
	// Boom Boom hit Zip Zap and strong force should be applied to him so that he can fly away like a projectile
	rotation.Yaw = directionRotation;
	flipbook->SetWorldRotation(rotation);
	flipbook->SetFlipbook(projectileFly);
	//characterSpeed = 450.f;
	charMove->GravityScale = 0.7f;
	characterState = State2::Combo_Projectile;

	// Calculate impulse vector

	float X_ImpulseDirection = 800.f;

	if (rotation.Yaw > 0) // Looking left
	{
		X_ImpulseDirection *= -1.f;
	}

	LaunchCharacter(FVector(X_ImpulseDirection, 0.f, 350.f), false, false);
}

void AZipZap::Electrify()
{
	if (characterState == State2::Combo_Projectile)
	{
		isElectrified = true;
		flipbook->SetFlipbook(projectileFlyElectrified);
	}
}

void AZipZap::SetupPlayerInput(UInputComponent* input_)
{
	Input = input_;

	Input->BindAxis("MoveZipZap", this, &AZipZap::move);
	Input->BindAxis("ClimbZipZap", this, &AZipZap::climb);
	Input->BindAction("JumpZipZap", IE_Pressed, this, &AZipZap::ExecuteJump);
	Input->BindAction("InitiateComboAttack_Savage", IE_Pressed, this, &AZipZap::InitiateComboAttack_Savage);
	Input->BindAction("ElectrifyZipZap", IE_Pressed, this, &AZipZap::Electrify);
	Input->BindAction("ShootZipZap", IE_Pressed, this, &AZipZap::Shoot);
}

void AZipZap::EndAttack()
{
	// Once an attack animation has finished, reset the character's state to "idle" and his flipbook's looping property to true, since only the attack animations shouldn't loop
	if (characterState != State2::Dead && characterState != State2::Jumping)
	{
		damageDealt = false;
		savageInitiated = false;
	    characterState = State2::Idle;
	    flipbook->SetLooping(true);
	    flipbook->Play();
	}
}

void AZipZap::UpdateState()
{
	charMove->MaxWalkSpeed = characterSpeed;

	// Execute attacking functions depending on the flipbook's frame position
	if (characterState == State2::Attacking && flipbook->GetFlipbook() != initiateBoomBoomSavageComboAttack)
	{
		if (flipbook->GetPlaybackPositionInFrames() == 3 && !damageDealt)
		{
			ProcessShoot(25.f);
			damageDealt = true;
		}
	}
	else if (characterState == State2::Attacking && flipbook->GetFlipbook() == initiateBoomBoomSavageComboAttack)
	{
		if (flipbook->GetPlaybackPositionInFrames() == 3 && !savageInitiated)
		{
			boomBoom->InitiateComboAttack_Savage(rotation.Yaw);
			savageInitiated = true;
		}
	}
}

void AZipZap::ExecuteJump()
{
	if (characterState != State2::Dead)
	{
		if ((characterState != State2::Combo_Projectile) && (characterState != State2::Attacking) && !charMove->IsFalling() && characterState != State2::Hurt && characterState != State2::Siege && inputAvailable)
		{
			if (canClimb)
			{
				SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 10.f));
				return;
			}

			Jump();
			characterState = State2::Jumping;
			flipbook->SetLooping(false);
			flipbook->SetFlipbook(jumping);
		}
	}
}

void AZipZap::climb(float scaleVal)
{
	if (characterState != State2::Dead)
	{
		if (characterState != State2::Attacking && characterState != State2::Hurt)
		{
			if (canClimb == true)
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

void AZipZap::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
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
			FVector loc = GetActorLocation();
			loc.Y -= 0.1;
			loc.Z += 30;
			AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(zap, loc, GetActorRotation());
			cfx->spriteChanger(5);
			setHealth(health - 10.f);
		}
		if (otherActor->IsA(AEnemy::StaticClass()))
		{
			if (characterState == State2::Combo_Projectile)
			{
				if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
				{
					if (isElectrified)
					{
						UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlashParticle, Enemy->GetActorLocation(), FRotator(0.f, 0.f, 0.f), FVector(2.f, 2.f, 2.f));
						impact->CustomTimeDilation = 3.f;
						Enemy->TakeEnemyDamage(90.f);
					}
					else
					{
						Enemy->TakeEnemyDamage(60.f);
					}

					Enemy->LaunchCharacter(FVector(charMove->Velocity.X / 3.f, charMove->Velocity.Y, charMove->Velocity.Z), false, false);
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

void AZipZap::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
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
			charMove->GravityScale = 1.0f;
			charMove->MovementMode = (TEnumAsByte<EMovementMode>)1;
		}
	}
}

bool AZipZap::IsFacingBoomBoom()
{
	// Boom Boom is on the left and Zip Zap is looking left
	if ((boomBoom->GetActorLocation().X < GetActorLocation().X) && rotation.Yaw > 0.f)
	{
		return true;
	}
	else if ((boomBoom->GetActorLocation().X < GetActorLocation().X) && rotation.Yaw <= 0.f) // Boom Boom is on the left and Zip Zap is looking right
	{
		return false;
	}
	else if ((boomBoom->GetActorLocation().X > GetActorLocation().X) && rotation.Yaw > 0.f) // Boom Boom is on the right and Zip Zap is looking left
	{
		return false;
	}
	else if ((boomBoom->GetActorLocation().X > GetActorLocation().X) && rotation.Yaw <= 0.f) // Boom Boom is on the right and Zip Zap is looking right
	{
		return true;
	}

	return false;
}

void AZipZap::ProcessShoot(float damage_)
{
	FVector muzzleFlashLocation = FVector(GetActorLocation().X + 138.f, GetActorLocation().Y, GetActorLocation().Z - 22.f);

	if (rotation.Yaw > 0.f) // Left
	{
		muzzleFlashLocation.X -= 276.f;
	}

	UParticleSystemComponent* muzzleFlash = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlashParticle, muzzleFlashLocation, FRotator(0.f, 0.f, 0.f), FVector(.2f, .2f, .2f));
	muzzleFlash->CustomTimeDilation = 3.f;

	// Spawn electric charge
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(electricChargeClass, muzzleFlashLocation, rotation);

	// Spawn Comic VFX
	FVector location = GetActorLocation();
	location.Z += 30.f;
	location.Y -= 0.1f;
	AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(zap, location, GetActorRotation());
	cfx->spriteChanger(0);

	// Check for close range collision
	FHitResult OutHit;
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(boomBoom);
	actorsToIgnore.Add(UGameplayStatics::GetActorOfClass(GetWorld(), ASiege::StaticClass()));
	bool hit = UKismetSystemLibrary::LineTraceSingle(this, GetActorLocation(), muzzleFlashLocation, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::Persistent, OutHit, true);
	if (hit)
	{
		AActor* HitActor = OutHit.GetActor();
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, HitActor->GetName());

		if (AEnemy* Enemy = Cast<AEnemy>(HitActor))
		{
			Enemy->TakeEnemyDamage(damage_);
			AComicFX* cfx2 = GetWorld()->SpawnActor<AComicFX>(zap, Enemy->GetActorLocation(), GetActorRotation());
			cfx2->spriteChanger(3);
			Enemy->TakeEnemyDamage(damage_);
		}

		if (AButton_But_Awesome* button = Cast<AButton_But_Awesome>(HitActor))
		{
			button->ButtPress();
		}
	}
}

void AZipZap::Shoot()
{
	if (characterState != State2::Dead && inputAvailable)
	{
		if (characterState != State2::Combo_Projectile && characterState != State2::Siege && !charMove->IsFalling())
		{
			isShooting = true;
			characterState = State2::Attacking;
			flipbook->SetLooping(false);
			flipbook->SetFlipbook(simpleAttack);
		}
	}
}