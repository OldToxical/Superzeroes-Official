// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashCan.h"
#include "Enemy.h"
#include "LevelManager.h"
#include "Components/BoxComponent.h"

ATrashCan::ATrashCan()
{
	PrimaryActorTick.bCanEverTick = true;
	sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	sprite->SetupAttachment(RootComponent);
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	capsule->SetupAttachment(RootComponent);
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeLocation(FVector(-125.0,0.0,491.666678));
	hitbox->SetRelativeScale3D(FVector(16.91, 0.5, 28.66));
	hitbox->SetupAttachment(RootComponent); 
	trashMovingLeft = false;
	canSpawn = true;
	health = 100.f;
	hurtTime = 0.0f; 

}

ATrashCan::~ATrashCan()
{

}

void ATrashCan::setHealth(float newHealth)
{
	if(GetRenderComponent()->GetSprite() != hurt)
	{
		health += newHealth;
	}
	if (newHealth < health)
	{
		RootComponent->SetMobility(EComponentMobility::Movable);
		GetRenderComponent()->SetSprite(hurt);
		RootComponent->SetMobility(EComponentMobility::Static);
	}
}

void ATrashCan::BeginPlay()
{
	Super::BeginPlay();
	timeBetweenShoots = 0.0f;
	RootComponent->SetMobility(EComponentMobility::Movable);
	GetRenderComponent()->SetSprite(idle);
	RootComponent->SetMobility(EComponentMobility::Static);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ATrashCan::overlapBegin);
	hitbox->OnComponentEndOverlap.AddDynamic(this, &ATrashCan::overlapEnd); 
}

void ATrashCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeBetweenShoots += DeltaTime;
	//UE_LOG(LogTemp,Warning,TEXT("spunch bob"));
	if (health <= 0.0f)
	{
		Cast<ALevelManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManager::StaticClass()))->RemoveTrashCan(this);
		Destroy();
	}
	if (timeBetweenShoots >= ShootTime && canSpawn == true)
	{
		FVector location (GetActorLocation().X, GetActorLocation().Y + 0.4f, GetActorLocation().Z + 150.0f);
		if (Trash_BP)
		{
			ATrash* trash = GetWorld()->SpawnActor<ATrash>(Trash_BP,location,GetActorRotation());
			if (trashMovingLeft)
			{
				trash->movingLeft = true;
			}
		}
		timeBetweenShoots = 0.0f;
	}
	if (GetRenderComponent()->GetSprite() == hurt)
	{
		hurtTime += DeltaTime;
		if (hurtTime >= 0.5f)
		{
			RootComponent->SetMobility(EComponentMobility::Movable);
			GetRenderComponent()->SetSprite(idle);
			RootComponent->SetMobility(EComponentMobility::Static);
			hurtTime = 0.0f;
		}
	}
}

void ATrashCan::overlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& result)
{
	if (otherActor && (otherActor != this) && otherComp)
	{
		if (otherActor->ActorHasTag(TEXT("BoomBoom")) || otherActor->ActorHasTag(TEXT("ZipZap")))
		{
			canSpawn = false;
		}
	}
}

void ATrashCan::overlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
	UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && (otherActor != this) && otherComp)
	{	
		if (otherActor->ActorHasTag(TEXT("BoomBoom")) || otherActor->ActorHasTag(TEXT("ZipZap")))
		{
			canSpawn = true;
		}
	}
}