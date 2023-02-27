// Fill out your copyright notice in the Description page of Project Settings.


#include "ZipZap.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "BoomBoom.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AZipZap::AZipZap()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	jumpPreludeTimer = 0.f;
	projectileAttackResetStateTimeoutTimer = 0.f;
	isElectrified = false;
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
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));
	hitbox->SetRelativeLocation(FVector(8.0, 0.0, 0.0));
	hitbox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AZipZap::BeginPlay()
{
	Super::BeginPlay();
	flipbook->SetFlipbook(idle);
	rotation = FRotator::ZeroRotator;
	charMove = GetCharacterMovement();

	if (boomBoom != NULL)
	{
		MoveIgnoreActorAdd(boomBoom->GetOwner());
	}
}

// Called every frame
void AZipZap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();
	UpdateState();

	//Boom Boom's savage attack is triggered using a different button for zip zap's attacking
	/*// If zip zap is attacking, check the hitbox for collision
	if (characterState == State2::Attacking)
	{
		HitCheck();
	}*/
}

void AZipZap::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping)
		{
			characterState = State2::Running;
			flipbook->SetFlipbook(run);
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State2::Attacking && characterState != State2::Combo_Projectile && characterState != State2::Jumping)
		{
			characterState = State2::Idle;
			flipbook->SetFlipbook(idle);
		}
	}
}

void AZipZap::move(float scaleVal)
{
	// Add movement force only if the character is not in a state of savage attack
	if (characterState != State2::Combo_Projectile)
	{
		characterSpeed = 350.f;
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);

		// Handle rotation
		if (scaleVal > 0.f)
		{
			rotation.Yaw = 0.f;
			flipbook->SetWorldRotation(rotation);
			hitbox->SetRelativeLocation(FVector(8.0, 0.0, 0.0));
		}
		else if (scaleVal < 0.f)
		{
			rotation.Yaw = 180.0f;
			flipbook->SetWorldRotation(rotation);
			hitbox->SetRelativeLocation(FVector(-8.0, 0.0, 0.0));
		}
	}
}

void AZipZap::InitiateComboAttack_Savage()
{
	if (boomBoom != NULL)
	{
		float proximityToBoomBoom = abs(boomBoom->GetActorLocation().X - GetActorLocation().X);

		if (proximityToBoomBoom <= MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack)
		{
			if (IsFacingBoomBoom())
			{
				boomBoom->InitiateComboAttack_Savage(rotation.Yaw);
				flipbook->SetLooping(false);
				flipbook->SetFlipbook(initiateBoomBoomSavageComboAttack);
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
	characterSpeed = 450.f;
	charMove->GravityScale = 0.7f;
	characterState = State2::Combo_Projectile;
	projectileAttackResetStateTimeoutTimer = 0.2f;

	// Calculate impulse vector
	float X_ImpulseDirection = 500.f;

	if (rotation.Yaw > 0) // Looking left
	{
		X_ImpulseDirection *= -1.f;
	}

	LaunchCharacter(FVector(X_ImpulseDirection, 0.f, 300.f), false, false);
}

void AZipZap::UpdateComboAttack_Projectile()
{
	HitCheck();
}

void AZipZap::Electrify()
{
	if (characterState == State2::Combo_Projectile)
	{
		isElectrified = true;
	}
}

void AZipZap::SetupPlayerInput(UInputComponent* input_)
{
	Input = input_;

	Input->BindAxis("MoveZipZap", this, &AZipZap::move);
	Input->BindAction("AttackZipZap", IE_Pressed, this, &AZipZap::Attack);
	Input->BindAction("JumpZipZap", IE_Pressed, this, &AZipZap::ExecuteJump);
	Input->BindAction("InitiateComboAttack_Savage", IE_Pressed, this, &AZipZap::InitiateComboAttack_Savage);
	Input->BindAction("ElectrifyZipZap", IE_Pressed, this, &AZipZap::Electrify);
}

void AZipZap::Attack()
{
	// Allow the execution of the simple attack only if the character is not in a state of savage attack
	if (characterState != State2::Combo_Projectile)
	{
		// Change the state to "attacking"
		characterState = State2::Attacking;
		flipbook->SetLooping(false);
		flipbook->SetFlipbook(simpleAttack);
	}
}

void AZipZap::EndAttack()
{
	// Once an attack animation has finished, reset the character's state to "idle" and his flipbook's looping property to true, since only the attack animations shouldn't loop
	flipbook->SetLooping(true);
	flipbook->Play();
	characterState = State2::Idle;
}

void AZipZap::UpdateState()
{
	charMove->MaxWalkSpeed = characterSpeed;

	if (characterState == State2::Combo_Projectile)
	{
		UpdateComboAttack_Projectile();
	}

	// Always decrease the jump prelude timer
	if (jumpPreludeTimer > 0.f)
	{
		jumpPreludeTimer -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		if (characterState == State2::Jumping && !charMove->IsFalling())
		{
			Jump();
			jumpPreludeTimer = 1.5f;
		}
	}

	// Enable movement once the projectile combo attack stopped
	if (characterState == State2::Combo_Projectile && !charMove->IsFalling())
	{
		projectileAttackResetStateTimeoutTimer -= GetWorld()->GetDeltaSeconds();

		if (projectileAttackResetStateTimeoutTimer <= 0.f)
		{
			StopProjectileAttack();
		}
	}
}

void AZipZap::ExecuteJump()
{
	if ((characterState != State2::Combo_Projectile) && (characterState != State2::Attacking) && !charMove->IsFalling())
	{
		jumpPreludeTimer = 0.27f;
		characterState = State2::Jumping;
		flipbook->SetLooping(false);
		flipbook->SetFlipbook(jumping);
	}
}

void AZipZap::HitCheck()
{	
	TArray<AActor*> output;
	// To be changed when enemies are present: detect hits only with enemies and deal damage
	/*GetOverlappingActors(output, ABoomBoom::StaticClass());
	// Go through each overlapping body
	for (int i = 0; i < output.Num(); i++)
	{
		ABoomBoom* bb;
		bb = (ABoomBoom*)UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass());
		bb->InitiateComboAttack_Savage(0.0f);
	}*/
}

void AZipZap::StopProjectileAttack()
{
	characterState = State2::Idle;
	charMove->GravityScale = 1.f;
	isElectrified = false;
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