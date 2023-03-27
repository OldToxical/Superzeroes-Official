// Fill out your copyright notice in the Description page of Project Settings.


#include "WindowTrigger.h"

AWindowTrigger::AWindowTrigger()
{
	flipbook = nullptr;
}

void AWindowTrigger::BreakWindow()
{
	if (flipbook)
	{
		flipbook->PlayFromStart();
	}

	for (auto pole : windowPoles)
	{
		pole->DestroyComponent();
	}
}

void AWindowTrigger::BeginPlay()
{
	Super::BeginPlay();

	if (flipbook)
	{
		flipbook->SetLooping(false);
		flipbook->SetPlaybackPosition(0, false);
		flipbook->Stop();
	}
}