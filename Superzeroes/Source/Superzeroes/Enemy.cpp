#include "Enemy.h"
#include "TrashCan.h"

AEnemy::AEnemy()
{
	characterMovementComponent = nullptr;
	flipbookComponent = nullptr;
	TimeBetweenWalkSounds = 5.0f;
	walkSoundTimer = TimeBetweenWalkSounds;
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	//UpdateActorState();
	//UpdateRotation();
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	characterMovementComponent = GetCharacterMovement();

	TSubclassOf<ATrashCan> subclass;
	subclass = ATrashCan::StaticClass();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), subclass, actorsToIgnore);
	for (AActor* actorToIgnore : actorsToIgnore)
	{
		GetCapsuleComponent()->IgnoreActorWhenMoving(actorToIgnore, true);
	}

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