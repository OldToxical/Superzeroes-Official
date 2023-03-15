// Fill out your copyright notice in the Description page of Project Settings.


#include "LAdder.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"

ALAdder::ALAdder()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeLocation(FVector(6.516138,0.000000, 17.729661));
	hitbox->SetRelativeScale3D(FVector(0.340833,1.000000,1.400000));
	hitbox->SetupAttachment(RootComponent);
	isActivated = false;
}

ALAdder::~ALAdder()
{

}

void ALAdder::BeginPlay()
{
	Super::BeginPlay();
	isActivated = false;
	GetRenderComponent()->SetFlipbook(ladder);
	GetRenderComponent()->SetLooping(false);
	GetRenderComponent()->SetPlaybackPositionInFrames(0,false);
	GetRenderComponent()->Stop();
	hitbox->SetCollisionProfileName("NoCollision");
}

void ALAdder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isActivated)
	{
		GetRenderComponent()->Play();
		hitbox->SetCollisionProfileName("OverlapAll");
	}
}

void ALAdder::Activation()
{
	isActivated = true;
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Yippee!"));
}

