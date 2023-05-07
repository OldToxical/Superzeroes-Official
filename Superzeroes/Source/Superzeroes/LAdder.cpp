// Fill out your copyright notice in the Description page of Project Settings.


#include "LAdder.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"

ALAdder::ALAdder()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeLocation(FVector(6.516138, 0.000000, 137.831809));
	hitbox->SetRelativeScale3D(FVector(0.840833, 0.25, 12.050000));
	hitbox->SetupAttachment(RootComponent);
	isActivated = false; 
	ladderNumber = 0; //CHANGE THIS IN BLUEPRINT!!! One button is connected to one ladder, and this number tells the button which ladder to connect to.
	//Added as safeproofing in case a level has multiple ladders
}

ALAdder::~ALAdder()
{

}

void ALAdder::BeginPlay()
{
	Super::BeginPlay();
	
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
}

