// Fill out your copyright notice in the Description page of Project Settings.


#include "ComicFX.h"
#include "PaperSpriteComponent.h"

AComicFX::AComicFX()
{
	PrimaryActorTick.bCanEverTick = true;
}

AComicFX::~AComicFX()
{

}

void AComicFX::BeginPlay()
{
	Super::BeginPlay();
	GetRenderComponent()->SetCollisionProfileName("NoCollision");
	location = GetActorLocation();
}

void AComicFX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	location.Z += 0.3;
	SetActorLocation(FVector(location.X, location.Y, location.Z));
	FLinearColor color = GetRenderComponent()->GetSpriteColor();
	color.A -= 0.01;
	GetRenderComponent()->SetSpriteColor(color);

	if (color.A <= 0.f)
	{
		Destroy();
	}
}

void AComicFX::spriteChanger(int i)
{
	switch (i)
	{
		case 0: GetRenderComponent()->SetSprite(zap); break;
		case 1: GetRenderComponent()->SetSprite(squeak); break;
		case 2: GetRenderComponent()->SetSprite(squawk); break;
		case 3: GetRenderComponent()->SetSprite(bang); break;
		case 4: GetRenderComponent()->SetSprite(oof); break;
		case 5: GetRenderComponent()->SetSprite(bam); break;
		case 6: GetRenderComponent()->SetSprite(number_0); break;
		case 7: GetRenderComponent()->SetSprite(number_1); break;
		case 8: GetRenderComponent()->SetSprite(number_2); break;
		case 9: GetRenderComponent()->SetSprite(number_3); break;
		case 10: GetRenderComponent()->SetSprite(number_4); break;
		case 11: GetRenderComponent()->SetSprite(number_5); break;
		default:GetRenderComponent()->SetSprite(zap); break;
	}
}