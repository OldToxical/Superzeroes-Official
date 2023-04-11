#include "Enemy.h"

AEnemy::AEnemy()
{
	characterMovementComponent = NULL;
	flipbookComponent = NULL;
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	
	TimeBetweenWalkSounds = 5.0f;
	walkSoundTimer = TimeBetweenWalkSounds;

	//UpdateActorState();
	//UpdateRotation();
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	characterMovementComponent = GetCharacterMovement();

	if (flipbookComponent)
	{
		flipbookComponent->bOwnerNoSee = false;
		flipbookComponent->bAffectDynamicIndirectLighting = true;
		flipbookComponent->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		//flipbookComponent->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("MainCharacter"));
		flipbookComponent->SetCollisionProfileName(CollisionProfileName);
		flipbookComponent->SetGenerateOverlapEvents(false);
		flipbookComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}
}

void AEnemy::AI()
{
}

void AEnemy::UpdateAnimation()
{
	
}

void AEnemy::UpdateRotation()
{
	if (characterMovementComponent)
	{
		if (characterMovementComponent->Velocity.X > 0.f)
		{
			rotation.Yaw = 0.f;
		}
		else
		{
			rotation.Yaw = 180.f;
		}

		GetCapsuleComponent()->SetRelativeRotation(rotation);
	}
}

void AEnemy::TakeEnemyDamage(float damage_)
{
}
