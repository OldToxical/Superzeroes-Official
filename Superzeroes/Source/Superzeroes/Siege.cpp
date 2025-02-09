// Fill out your copyright notice in the Description page of Project Settings.


#include "Siege.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

ASiege::ASiege()
{
	boomBoom = nullptr;
	zipZap = nullptr;
	charMove = nullptr;
	electricChargeClass = nullptr;
	initiationAnimationUserWidget = nullptr;
	rotation = FRotator::ZeroRotator;
	executionTimer = SiegeModeExecutionLength;
	boomBoomInputTimer = 0.f;
	zipZapInputTimer = 0.f;
	bullets = 50;
	inititationAnimationTimer = InitiationAnimationLength;
	modeIsActive = false;
	shotFired = false;
	inputAvailable = false;
	isSpawningProjectileAvailable = true;
	state = SiegeState::Idle;

	flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	if (flipbook)
	{
		flipbook->bOwnerNoSee = false;
		flipbook->bAffectDynamicIndirectLighting = true;
		flipbook->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		flipbook->SetupAttachment(GetCapsuleComponent());
		flipbook->SetCollisionProfileName(TEXT("NoCollision"));
		flipbook->SetGenerateOverlapEvents(false);
	}
}

void ASiege::BeginPlay()
{
	Super::BeginPlay();

	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ASiege::overlapBegin);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("NoCollision"));
	SetActorHiddenInGame(true);
	flipbook->SetFlipbook(idle);
	flipbook->SetLooping(false);
	flipbook->Stop();
	flipbook->OnFinishedPlaying.AddDynamic(this, &ASiege::EndAttackAnimation);
	boomBoom = Cast<ABoomBoom>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass()));
	zipZap = Cast<AZipZap>(UGameplayStatics::GetActorOfClass(GetWorld(), AZipZap::StaticClass()));
	SetupBoomBoomInputComponent(boomBoom->InputComponent);
}

void ASiege::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();

	if (boomBoomInputTimer >= InputTime && zipZapInputTimer >= InputTime && !modeIsActive)
	{
		SetActorRotation(boomBoom->GetActorRotation());
		bullets = 50;
		modeIsActive = true;
		boomBoom->setMeter(-100.f);
		zipZap->setMeter(-100.f);
		UGameplayStatics::PlaySound2D(GetWorld(), siegeActivate);
		UGameplayStatics::PlaySound2D(GetWorld(), siegeVoice);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(2.f, 2.f, true, true, true, true);
		UGameplayStatics::GetPlayerController(GetWorld(), 1)->PlayDynamicForceFeedback(2.f, 2.f, true, true, true, true);
		flipbook->Play();
	}

	if (modeIsActive)
	{
		if (inititationAnimationTimer > 0.f)
		{
			initiationAnimationUserWidget->AddToViewport();
			inititationAnimationTimer -= GetWorld()->GetDeltaSeconds();
		}
		else
		{
			initiationAnimationUserWidget->RemoveFromViewport();
			inputAvailable = true;
		}

		ExecuteSiegeMode();
		return;
	}

	inititationAnimationTimer = InitiationAnimationLength;
	executionTimer = SiegeModeExecutionLength;
	inputAvailable = false;
	SetActorLocation(FVector(boomBoom->GetActorLocation().X, boomBoom->GetActorLocation().Y, boomBoom->GetActorLocation().Z + 100.f));
}

void ASiege::SetupBoomBoomInputComponent(UInputComponent* bbInput)
{
	bbInput->BindAxis("SiegeBoomBoom", this, &ASiege::HandleBoomBoomInput);
	bbInput->BindAxis("MoveBoomBoom", this, &ASiege::Move);
}

void ASiege::SetupZipZapInputComponent(UInputComponent* zzInput)
{
	zzInput->BindAxis("SiegeZipZap", this, &ASiege::HandleZipZapInput);
	zzInput->BindAction("ShootZipZap", IE_Pressed, this, &ASiege::Shoot);
}

void ASiege::HandleBoomBoomInput(float scaleVal)
{
	if (scaleVal > 0.f)
	{
		float distanceX = abs(boomBoom->GetActorLocation().X - zipZap->GetActorLocation().X);
		float distanceZ = abs(boomBoom->GetActorLocation().Z - zipZap->GetActorLocation().Z);

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode && boomBoom->GetState() == BB_State::Idle && boomBoom->getMeter() >= 100.f)
		{
			boomBoomInputTimer += GetWorld()->GetDeltaSeconds();
			boomBoom->SetInputAvailability(false);
			boomBoom->EnableSiegeInitiationParticle();
			return;
		}
	}

	boomBoomInputTimer = 0.f;
	boomBoom->SetInputAvailability(true);
	boomBoom->DisableSiegeInitiationParticle();
}

void ASiege::HandleZipZapInput(float scaleVal)
{
	if (scaleVal > 0.f)
	{
		float distanceX = abs(boomBoom->GetActorLocation().X - zipZap->GetActorLocation().X);
		float distanceZ = abs(boomBoom->GetActorLocation().Z - zipZap->GetActorLocation().Z);

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode && zipZap->GetState() == ZZ_State::Idle && zipZap->getMeter() >= 100.f)
		{
			zipZapInputTimer += GetWorld()->GetDeltaSeconds();
			zipZap->SetInputAvailability(false);
			zipZap->EnableSiegeInitiationParticle();
			return;
		}
	}

	zipZapInputTimer = 0.f;
	zipZap->SetInputAvailability(true);
	zipZap->DisableSiegeInitiationParticle();
}

void ASiege::ExecuteSiegeMode()
{
	if (executionTimer > 0.f)
	{
		if (bullets > 0)
		{
			executionTimer -= GetWorld()->GetDeltaSeconds();

			GetCapsuleComponent()->SetCollisionProfileName(TEXT("MainCharacter"));
			SetActorHiddenInGame(false);
			boomBoom->SetActorHiddenInGame(true);
			boomBoom->SetState(BB_State::Siege);
			zipZap->SetActorHiddenInGame(true);
			zipZap->SetState(ZZ_State::Siege);

			boomBoom->SetActorLocation(GetActorLocation());
			zipZap->SetActorLocation(FVector(GetActorLocation().X + 50.f, GetActorLocation().Y + .01f, GetActorLocation().Z));

			if (flipbook->GetPlaybackPositionInFrames() == 4 && shotFired)
			{
				FVector muzzleFlashLocation = FVector(GetActorLocation().X + 150.f, GetActorLocation().Y, GetActorLocation().Z + 35.f);

				if (rotation.Yaw > 0.f) // Left
				{
					muzzleFlashLocation.X -= 300.f;
				}

				// Check for close range collision
				FHitResult OutHit;
				TArray<AActor*> actorsToIgnore;
				actorsToIgnore.Add(boomBoom);
				actorsToIgnore.Add(zipZap);
				actorsToIgnore.Add(UGameplayStatics::GetActorOfClass(GetWorld(), ASiege::StaticClass()));
				bool hit = UKismetSystemLibrary::LineTraceSingle(this, GetActorLocation(), muzzleFlashLocation, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, actorsToIgnore, EDrawDebugTrace::None, OutHit, true);
				
				if (hit)
				{
					AActor* HitActor = OutHit.GetActor();

					if (AEnemy* Enemy = Cast<AEnemy>(HitActor))
					{
						Enemy->TakeEnemyDamage(125.f);
					}
				}

				UParticleSystemComponent* muzzleFlashParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlash, muzzleFlashLocation, FRotator(0.f, 0.f, 0.f), FVector(.6f, .6f, .6f));
				muzzleFlashParticle->CustomTimeDilation = 3.f;
				if ((isSpawningProjectileAvailable) || (!isSpawningProjectileAvailable && rotation.Yaw > 0.f))
				{
					AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(electricChargeClass, muzzleFlashLocation, rotation);
				}
				UGameplayStatics::PlaySound2D(GetWorld(), siegeShoot);
				UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, .2f, true, true, true, true);
				UGameplayStatics::GetPlayerController(GetWorld(), 1)->PlayDynamicForceFeedback(1.f, .2f, true, true, true, true);
				shotFired = false;
				bullets--;
			}

			return;
		}
	}

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("NoCollision"));
	SetActorHiddenInGame(true);
	boomBoom->SetActorHiddenInGame(false);
	boomBoom->SetState(BB_State::Idle);
	zipZap->SetActorHiddenInGame(false);
	zipZap->SetState(ZZ_State::Idle);
	executionTimer = SiegeModeExecutionLength;
	modeIsActive = false;
}

void ASiege::Move(float scaleVal)
{
	if (modeIsActive && inputAvailable)
	{
		if (scaleVal > 0.f) // Right
		{
			if (state != SiegeState::Attacking)
			{
				state = SiegeState::Walking;
			}

			if (flipbook->GetFlipbook() == walk && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 1 || flipbook->GetPlaybackPositionInFrames() == 9) && !charMove->IsFalling())
			{
				stepMade = true;
				smokeParticle->ActivateSystem();
				UGameplayStatics::PlaySound2D(GetWorld(), siegeWalk);
				UGameplayStatics::PlayWorldCameraShake(GetWorld(), cameraShakeLandBP, GetActorLocation(), 0.f, 2000.f, 1.f, false);
				UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, .15f, true, true, true, true);
				UGameplayStatics::GetPlayerController(GetWorld(), 1)->PlayDynamicForceFeedback(1.f, .15f, true, true, true, true);
			}

			if (flipbook->GetFlipbook() == walk && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 10))
			{
				stepMade = false;
			}

			AddMovementInput(FVector(1.f, 0.f, 0.f), 0.4f, false);
			rotation.Yaw = 0.f;
		}
		else if (scaleVal < 0.f) // Left
		{
			if (state != SiegeState::Attacking)
			{
				state = SiegeState::Walking;
			}

			if (flipbook->GetFlipbook() == walk && !stepMade && (flipbook->GetPlaybackPositionInFrames() == 1 || flipbook->GetPlaybackPositionInFrames() == 9) && !charMove->IsFalling())
			{
				stepMade = true;
				smokeParticle->ActivateSystem();
				UGameplayStatics::PlaySound2D(GetWorld(), siegeWalk);
				UGameplayStatics::PlayWorldCameraShake(GetWorld(), cameraShakeLandBP, GetActorLocation(), 0.f, 2000.f, 1.f, false);
				UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayDynamicForceFeedback(1.f, .2f, true, true, true, true);
				UGameplayStatics::GetPlayerController(GetWorld(), 1)->PlayDynamicForceFeedback(1.f, .2f, true, true, true, true);
			}

			if (flipbook->GetFlipbook() == walk && (flipbook->GetPlaybackPositionInFrames() == 2 || flipbook->GetPlaybackPositionInFrames() == 10))
			{
				stepMade = false;
			}

			AddMovementInput(FVector(-1.f, 0.f, 0.f), 0.4f, false);
			rotation.Yaw = 180.f;
		}
		else
		{
			if (state != SiegeState::Attacking)
			{
				flipbook->SetFlipbook(idle);
				state = SiegeState::Idle;
			}
		}

		SetActorRotation(rotation);
	}
}

void ASiege::Shoot()
{
	if (state != SiegeState::Attacking && inputAvailable)
	{
		state = SiegeState::Attacking;
		shotFired = true;
	}
}

void ASiege::UpdateAnimation()
{
	switch (state)
	{
	    case SiegeState::Idle:
			flipbook->SetFlipbook(idle);
			flipbook->SetLooping(true);
		break;
		    case SiegeState::Walking:
			flipbook->SetFlipbook(walk);
			flipbook->SetLooping(true);
		break;
		    case SiegeState::Attacking:
			flipbook->SetFlipbook(attack);
			flipbook->SetLooping(false);
		break;
		    default:
		break;
	}
}

void ASiege::EndAttackAnimation()
{
	state = SiegeState::Idle;
	flipbook->SetLooping(true);
	flipbook->Play();
}

void ASiege::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor != this)
	{
		if (AEnemy* Enemy = Cast<AEnemy>(otherActor))
		{
			Enemy->TakeEnemyDamage(75.f);
		}

		if (otherActor->ActorHasTag("LevelRespawnTrigger"))
		{
			executionTimer = 0.f;
			boomBoom->Respawn();
			zipZap->Respawn();
		}

		if (otherActor->ActorHasTag("EndLevel") || otherActor->ActorHasTag("LevelTrigger"))
		{
			isSpawningProjectileAvailable = false;
		}
	}
}

void ASiege::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor->ActorHasTag("EndLevel") || otherActor->ActorHasTag("LevelTrigger"))
	{
		isSpawningProjectileAvailable = true;
	}
}