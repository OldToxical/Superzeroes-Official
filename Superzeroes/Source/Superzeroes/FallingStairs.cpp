// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingStairs.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"

AFallingStairs::AFallingStairs()
{
	PrimaryActorTick.bCanEverTick = true;
	isActivated = false;
	stairsNumber = 0; //CHANGE THIS IN BLUEPRINT!!! Functions the same as the ladder, activated by button which needs the number
}

AFallingStairs::~AFallingStairs()
{

}

void AFallingStairs::BeginPlay()
{
	Super::BeginPlay();
	isActivated = false;
	GetRenderComponent()->SetFlipbook(stairs);
	GetRenderComponent()->SetLooping(false);
	GetRenderComponent()->SetPlaybackPositionInFrames(0, false);
	GetRenderComponent()->Stop();
}

void AFallingStairs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isActivated)
	{
		GetRenderComponent()->Play();
	}
}

void AFallingStairs::Activation()
{
	isActivated = true;
}

