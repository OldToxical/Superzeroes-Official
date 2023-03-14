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
	shootCooldownTimer = 0.f;
	boomBoomInputTimer = 0.f;
	zipZapInputTimer = 0.f;
	modeIsActive = false;
	shotFired = false;

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
	SetActorHiddenInGame(true);
	flipbook->SetFlipbook(intro);
	flipbook->SetLooping(false);
	flipbook->Stop();
}

void ASiege::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (boomBoomInputTimer >= InputTime && zipZapInputTimer >= InputTime && !modeIsActive)
	{
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

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode)
		{
			boomBoomInputTimer += GetWorld()->GetDeltaSeconds();
			return;
		}
	}

	boomBoomInputTimer = 0.f;
}

void ASiege::HandleZipZapInput(float scaleVal)
{
	if (scaleVal > 0.f)
	{
		float distanceX = abs(boomBoom->GetActorLocation().X - zipZap->GetActorLocation().X);
		float distanceZ = abs(boomBoom->GetActorLocation().Z - zipZap->GetActorLocation().Z);

		if (distanceX <= MaximumXDistanceBetweenPlayersForInitiatingSiegeMode && distanceZ <= MaximumZDistanceBetweenPlayersForInitiatingSiegeMode)
		{
			zipZapInputTimer += GetWorld()->GetDeltaSeconds();
			return;
		}
	}

	zipZapInputTimer = 0.f;
}

void ASiege::ExecuteSiegeMode()
{
	if (executionTimer > 0.f)
	{
		executionTimer -= GetWorld()->GetDeltaSeconds();

		SetActorHiddenInGame(false);
		boomBoom->SetActorHiddenInGame(true);
		boomBoom->SetState(State::Siege);
		zipZap->SetActorHiddenInGame(true);
		zipZap->SetState(State2::Siege);

		boomBoom->SetActorLocation(GetActorLocation());
		zipZap->SetActorLocation(FVector(GetActorLocation().X + 50.f, GetActorLocation().Y, GetActorLocation().Z));

		if (flipbook->GetPlaybackPositionInFrames() == 4 && shotFired)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("atakuva"));
			FVector muzzleFlashLocation = FVector(GetActorLocation().X + 54.f, GetActorLocation().Y, GetActorLocation().Z - 5.f);
			FVector beamVelocity = FVector(50000.f, 0.f, 0.f);

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
			flipbook->SetFlipbook(walk);
			AddMovementInput(FVector(1.f, 0.f, 0.f), 0.4f, false);
			rotation.Yaw = 0.f;
		}
		else if (scaleVal < 0.f) // Left
		{
			flipbook->SetFlipbook(walk);
			AddMovementInput(FVector(-1.f, 0.f, 0.f), 0.4f, false);
			rotation.Yaw = 180.f;
		}
		else
		{
			if (flipbook->GetFlipbook() != attack)
			{
				flipbook->SetFlipbook(idle);
			}
		}

		SetActorRotation(rotation);
	}
}

void ASiege::Shoot()
{
	if (flipbook->GetFlipbook() != attack)
	{
		flipbook->SetFlipbook(attack);
		flipbook->SetLooping(false);
		shotFired = true;
	}
}

void ASiege::EndAttackAnimation()
{
	if (flipbook->GetFlipbook() == intro)
	{
		flipbook->SetFlipbook(idle);
	}

	flipbook->SetLooping(true);
	flipbook->Play();
	shootCooldownTimer = ShootCooldownTime;
}

void ASiege::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
}

void ASiege::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
}