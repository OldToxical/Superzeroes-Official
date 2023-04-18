// Fill out your copyright notice in the Description page of Project Settings.


#include "ZipZap.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
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
#include "Kismet/KismetStringLibrary.h"

// Sets default values
AZipZap::AZipZap()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	jumpPreludeTimer = 0.f;
	health = 100.f;
	timeToHeal = 10.f;
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
	healing = false;
	audComp = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
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

	TimeBetweenWalkSounds = 3.5f;
	walkSoundTimer = TimeBetweenWalkSounds;
	toxicWalkSoundBool = false;
}

void AZipZap::setHealth(float newHealth)
{
	if (characterState != State2::Siege)
	{
		if (characterState != State2::Hurt && characterState != State2::Attacking && characterState != State2::Combo_Projectile && newHealth < health)
		{
			healTimer = 0.f;
			healing = false;
			characterState = State2::Hurt;
			flipbook->SetFlipbook(hurt);
			flipbook->SetLooping(false);

			//hurt clip will play over and over without this
			if (!toxicDamage)
			{
				UGameplayStatics::PlaySound2D(GetWorld(), hurtSFX);
			}
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

	audComp->SetSound(flyingSFX);
	audComp->Stop();
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
	boomBoom = Cast<ABoomBoom>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass()));
	if (boomBoom)
	{
		boomBoom->SetZipZapReference(this);
	}

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
	spawnLoc.Add(FVector(9410.f, .5f, 2092.f)); // From here and below the X should decrease
}

// Called every frame
void AZipZap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (characterState != State2::Siege)
	{
		setMeter(refillTime);

		if (meter >= (99.9f - refillTime) && meter <= 99.9f)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), meterFull);
		}
	}

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

			if (healTimer >= timeToHeal && health < 100.f)
			{
				healing = true;
				UGameplayStatics::PlaySound2D(GetWorld(), healthRecharge);
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
			setHealth(health + 0.5f);
		}

		if (health <= 0.f)
		{
			int randomSound = rand() % 2 + 1;

			switch (randomSound)
			{
				case 1:	UGameplayStatics::PlaySound2D(GetWorld(), death1SFX);
				case 2:	UGameplayStatics::PlaySound2D(GetWorld(), death2SFX);
				case 3:	UGameplayStatics::PlaySound2D(GetWorld(), death3SFX);
			}

			characterState = State2::Dead;
			flipbook->SetFlipbook(dead);
			flipbook->SetLooping(false);
		}
	}
	else
	{
		deathTimer += DeltaTime;

		if (deathTimer >= respawnTime)
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
		audComp->Stop();
	}

	UGameplayStatics::PlaySound2D(GetWorld(), landSFX);
	characterState = State2::Idle;
	flipbook->SetLooping(true);
	flipbook->Play();
}

void AZipZap::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping && characterState != State2::Hurt && characterState != State2::Siege)
		{
			characterState = State2::Running;
			flipbook->SetFlipbook(run);
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping && characterState != State2::Hurt && characterState != State2::Siege)
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
				if (flipbook->GetFlipbook() == run && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 8) && !charMove->IsFalling())
				{
					if (toxicDamage)
					{
						switch (toxicWalkSoundBool)
						{
							case 0:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk1SFX);
							case 1:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk2SFX);
						}
						toxicWalkSoundBool = !toxicWalkSoundBool;
					}
					else
					{
						UGameplayStatics::PlaySound2D(GetWorld(), walkSFX);
						smokeParticle->ActivateSystem();
					}
					stepMade = true;
				}

				if (flipbook->GetFlipbook() == run && (flipbook->GetPlaybackPositionInFrames() == 3 || flipbook->GetPlaybackPositionInFrames() == 9))
				{
					stepMade = false;
				}

				rotation.Yaw = 0.f;
				flipbook->SetWorldRotation(rotation);
			}
			else if (scaleVal < 0.f)
			{
				if (flipbook->GetFlipbook() == run && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 8) && !charMove->IsFalling())
				{
					if (toxicDamage)
					{
						switch (toxicWalkSoundBool)
						{
							case 0:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk1SFX);
							case 1:	UGameplayStatics::PlaySound2D(GetWorld(), toxicWalk2SFX);
						}
						toxicWalkSoundBool = !toxicWalkSoundBool;
					}
					else
					{
						UGameplayStatics::PlaySound2D(GetWorld(), walkSFX);
						smokeParticle->ActivateSystem();
					}
					stepMade = true;
				}

				if (flipbook->GetFlipbook() == run && (flipbook->GetPlaybackPositionInFrames() == 3 || flipbook->GetPlaybackPositionInFrames() == 9))
				{
					stepMade = false;
				}

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
			if (characterState != State2::Siege && characterState != State2::Attacking && characterState != State2::Combo_Projectile && boomBoom->GetState() != State::Combo_Savage && boomBoom->GetState() != State::Dead && !boomBoom->charMove->IsFalling() && inputAvailable)
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
	audComp->Play();
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

void AZipZap::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Input = input_;

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Zip Zap has no input component"));
		return;
	}

	PlayerInputComponent->BindAxis("MoveZipZap", this, &AZipZap::move);
	PlayerInputComponent->BindAxis("ClimbZipZap", this, &AZipZap::climb);
	PlayerInputComponent->BindAction("JumpZipZap", IE_Pressed, this, &AZipZap::ExecuteJump);
	PlayerInputComponent->BindAction("InitiateComboAttack_Savage", IE_Pressed, this, &AZipZap::InitiateComboAttack_Savage);
	PlayerInputComponent->BindAction("ElectrifyZipZap", IE_Pressed, this, &AZipZap::Electrify);
	PlayerInputComponent->BindAction("ShootZipZap", IE_Pressed, this, &AZipZap::Shoot);

	FActorSpawnParameters spawnParameters;
	ESpawnActorCollisionHandlingMethod collisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	spawnParameters.SpawnCollisionHandlingOverride = collisionHandlingMethod;
	ASiege* siege = GetWorld()->SpawnActor<ASiege>(siegeBPClass, FVector(0.f, 0.5f, 0.f), FRotator(0.f, 0.f, 0.f), spawnParameters);
	if (siege)
	{
		siege->SetupZipZapInputComponent(InputComponent);
		siege->SpawnDefaultController();
	}
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
			FVector muzzleFlashLocation = FVector(GetActorLocation().X + 138.f, GetActorLocation().Y, GetActorLocation().Z - 22.f);

			if (rotation.Yaw > 0.f) // Left
			{
				muzzleFlashLocation.X -= 276.f;
			}

			UParticleSystemComponent* muzzleFlash = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlashParticle, muzzleFlashLocation, FRotator(0.f, 0.f, 0.f), FVector(.5f, .5f, .5f));
			muzzleFlash->CustomTimeDilation = 3.f;

			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), boomBoomImpact, FVector(boomBoom->GetActorLocation().X, boomBoom->GetActorLocation().Y + 30.f, boomBoom->GetActorLocation().Z), FRotator(0, 0, 0), FVector(1.3f, 1.3f, 1.3f));
		}
	}
}

void AZipZap::ExecuteJump()
{
	if (characterState != State2::Dead)
	{
		if ((characterState != State2::Combo_Projectile) && (characterState != State2::Attacking) && !charMove->IsFalling() && characterState != State2::Hurt && characterState != State2::Siege && inputAvailable && !canClimb)
		{
			/*if (canClimb)
			{
				SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 10.f));
				return;
			}*/

			Jump();
			characterState = State2::Jumping;
			flipbook->SetLooping(false);
			flipbook->SetFlipbook(jumping);
			UGameplayStatics::PlaySound2D(GetWorld(), jumpSFX);
		}
	}
}

void AZipZap::climb(float scaleVal)
{
	if (characterState != State2::Dead)
	{
		if (characterState != State2::Attacking && characterState != State2::Hurt)
		{
			if (canClimb == true && characterState != State2::Jumping)
			{
				if (scaleVal != 0)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::SanitizeFloat(scaleVal));
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
					FVector impactForce = FVector(400.f, 0.f, 180.f);

					if (isElectrified)
					{
						UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlashParticle, Enemy->GetActorLocation(), FRotator(0.f, 0.f, 0.f), FVector(1.f, 1.f, 1.f));
						impact->CustomTimeDilation = 3.f;
						Enemy->TakeEnemyDamage(90.f);
						impactForce.X += 100.f;
					}
					else
					{
						UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), enemyImpact, Enemy->GetActorLocation(), FRotator(0.f, 0.f, 0.f), FVector(.9f, .9f, .9f));
						Enemy->TakeEnemyDamage(60.f);
					}

					if (rotation.Yaw > 0.f) // Looking left
					{
						impactForce.X *= -1.f;
					}

					Enemy->LaunchCharacter(impactForce, false, false);
				}
			}
		}
		if (otherActor->IsA(ALAdder::StaticClass()))
		{
			if (characterState == State2::Running || characterState == State2::Idle) 
			{
				canClimb = true;
			}

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

	UParticleSystemComponent* muzzleFlash = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlashParticle, muzzleFlashLocation, FRotator(0.f, 0.f, 0.f), FVector(.5f, .5f, .5f));
	muzzleFlash->CustomTimeDilation = 3.f;

	// Spawn electric charge
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(electricChargeClass, muzzleFlashLocation, rotation);

	// Spawn Comic VFX
	FVector location = FVector(muzzleFlashLocation.X, muzzleFlashLocation.Y - 0.1f, GetActorLocation().Z + 70.f);
	AComicFX* cfx = GetWorld()->SpawnActor<AComicFX>(zap, location, GetActorRotation());
	cfx->spriteChanger(0);

	// Check for close range collision
	FHitResult OutHit;
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(boomBoom);
	actorsToIgnore.Add(UGameplayStatics::GetActorOfClass(GetWorld(), ASiege::StaticClass()));
	bool hit = UKismetSystemLibrary::LineTraceSingle(this, GetActorLocation(), muzzleFlashLocation, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::None, OutHit, true);
	if (hit)
	{
		AActor* HitActor = OutHit.GetActor();

		if (AEnemy* Enemy = Cast<AEnemy>(HitActor))
		{
			// Spawn Comic VFX
			FVector location_ = FVector(Enemy->GetActorLocation().X, Enemy->GetActorLocation().Y - 0.1f, Enemy->GetActorLocation().Z + 90.f);
			FVector impactForce = FVector(250.f, 0.f, 180.f);
			if (rotation.Yaw > 0) // Looking left
			{
				impactForce.X *= -1.f;
			}
			UParticleSystemComponent* impact = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), enemyImpact, Enemy->GetActorLocation(), FRotator(0.f, 0.f, 0.f), FVector(.9f, .9f, .9f));
			AComicFX* cfx2 = GetWorld()->SpawnActor<AComicFX>(zap, location_, GetActorRotation());
			cfx2->spriteChanger(3);
			Enemy->TakeEnemyDamage(damage_);
			Enemy->LaunchCharacter(impactForce, false, false);
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