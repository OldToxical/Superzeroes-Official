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
	Input = nullptr;
	charMove = nullptr;
	electricChargeClass = nullptr;
	rotation = FRotator::ZeroRotator;
	executionTimer = SiegeModeExecutionLength;
	boomBoomInputTimer = 0.f;
	zipZapInputTimer = 0.f;
	modeIsActive = false;
	shotFired = false;
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

ASiege::~ASiege()
{
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
}

void ASiege::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();

	if (boomBoomInputTimer >= InputTime && zipZapInputTimer >= InputTime && !modeIsActive)
	{
		SetActorRotation(boomBoom->GetActorRotation());
		modeIsActive = true;
		flipbook->Play();
	}

	if (modeIsActive)
	{
		ExecuteSiegeMode();
		return;
	}

	SetActorLocation(boomBoom->GetActorLocation());
}

void ASiege::SetupPlayerInput(UInputComponent* input_)
{
	Input = input_;

	Input->BindAxis("SiegeBoomBoom", this, &ASiege::HandleBoomBoomInput);
	Input->BindAxis("SiegeZipZap", this, &ASiege::HandleZipZapInput);
	Input->BindAxis("MoveBoomBoom", this, &ASiege::Move);
	Input->BindAction("ShootZipZap", IE_Pressed, this, &ASiege::Shoot);
}

void ASiege::HandleBoomBoomInput(float scaleVal)
{
	if (scaleVal > 0.f)
	{
		float distanceX = abs(boomBoom->GetActorLocation().X - zipZap->GetActorLocation().X);
		float distanceZ = abs(boomBoom->GetActorLocation().Z - zipZap->GetActorLocation().Z);

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode && boomBoom->GetState() == State::Idle)
		{
			boomBoomInputTimer += GetWorld()->GetDeltaSeconds();
			boomBoom->SetInputAvailability(false);
			return;
		}
	}

	boomBoomInputTimer = 0.f;
	boomBoom->SetInputAvailability(true);
}

void ASiege::HandleZipZapInput(float scaleVal)
{
	if (scaleVal > 0.f)
	{
		float distanceX = abs(boomBoom->GetActorLocation().X - zipZap->GetActorLocation().X);
		float distanceZ = abs(boomBoom->GetActorLocation().Z - zipZap->GetActorLocation().Z);

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode && zipZap->GetState() == State2::Idle)
		{
			zipZapInputTimer += GetWorld()->GetDeltaSeconds();
			zipZap->SetInputAvailability(false);
			return;
		}
	}

	zipZapInputTimer = 0.f;
	zipZap->SetInputAvailability(true);
}

void ASiege::ExecuteSiegeMode()
{
	if (executionTimer > 0.f)
	{
		executionTimer -= GetWorld()->GetDeltaSeconds();

		GetCapsuleComponent()->SetCollisionProfileName(TEXT("MainCharacter"));
		SetActorHiddenInGame(false);
		boomBoom->SetActorHiddenInGame(true);
		boomBoom->SetState(State::Siege);
		zipZap->SetActorHiddenInGame(true);
		zipZap->SetState(State2::Siege);

		boomBoom->SetActorLocation(GetActorLocation());
		zipZap->SetActorLocation(FVector(GetActorLocation().X + 50.f, GetActorLocation().Y, GetActorLocation().Z));

		if (flipbook->GetPlaybackPositionInFrames() == 4 && shotFired)
		{
			FVector muzzleFlashLocation = FVector(GetActorLocation().X + 54.f, GetActorLocation().Y, GetActorLocation().Z - 5.f);
			FVector beamVelocity = FVector(30000.f, 0.f, 0.f);

			if (rotation.Yaw > 0.f) // Left
			{
				muzzleFlashLocation.X -= 108.f;
				beamVelocity.X *= -1.f;
			}

			UNiagaraComponent* beam = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), electricBeam, muzzleFlashLocation, rotation);
			beam->SetVectorParameter("Velocity", beamVelocity);
			UParticleSystemComponent* muzzleFlashParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), muzzleFlash, muzzleFlashLocation, FRotator(0.f, 0.f, 0.f), FVector(.2f, .2f, .2f));
			muzzleFlashParticle->CustomTimeDilation = 3.f;
			AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(electricChargeClass, muzzleFlashLocation, rotation);
			shotFired = false;
		}

		return;
	}

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("NoCollision"));
	SetActorHiddenInGame(true);
	boomBoom->SetActorHiddenInGame(false);
	boomBoom->SetState(State::Idle);
	zipZap->SetActorHiddenInGame(false);
	zipZap->SetState(State2::Idle);
	executionTimer = SiegeModeExecutionLength;
	modeIsActive = false;
}

void ASiege::Move(float scaleVal)
{
	if (modeIsActive)
	{
		if (scaleVal > 0.f) // Right
		{
			if (state != SiegeState::Attacking)
			{
				state = SiegeState::Walking;
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
	if (state != SiegeState::Attacking)
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
			Enemy->TakeEnemyDamage(100.f);
		}
	}
}

void ASiege::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
}
