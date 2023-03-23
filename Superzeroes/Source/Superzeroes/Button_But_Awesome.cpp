// Fill out your copyright notice in the Description page of Project Settings.


#include "Button_But_Awesome.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "BoomBoom.h"
#include "ZipZap.h"
#include "LAdder.h"
#include "Kismet/GameplayStatics.h"

AButton_But_Awesome::AButton_But_Awesome()
{
	PrimaryActorTick.bCanEverTick = true;
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	hitbox->SetRelativeScale3D(FVector(15.3125, 7.625, 15.3125));
	hitbox->SetRelativeLocation(FVector(11.101960, 0, 0));
	hitbox->SetupAttachment(RootComponent);
	buttonNumber = 0; //CHANGE THIS IN BLUEPRINT!!! One button is connected to one ladder, and this number tells the button which ladder to connect to.
	//Added as safeproofing in case a level has multiple ladders
}

AButton_But_Awesome::~AButton_But_Awesome()
{

}

void AButton_But_Awesome::BeginPlay()
{
	Super::BeginPlay(); 
	GetRenderComponent()->SetFlipbook(button);
	GetRenderComponent()->SetLooping(false);
	GetRenderComponent()->Stop();
}

void AButton_But_Awesome::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AButton_But_Awesome::ButtPress()
{
	GetRenderComponent()->Play();
	TArray<AActor*> ladders;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALAdder::StaticClass(), ladders);
	
	for (int i = 0; i < ladders.Num(); i++)
	{
		ALAdder* oneLadder = (ALAdder*)ladders[i];
		if (oneLadder->ladderNumber == buttonNumber)
		{
			oneLadder->Activation();
		}
	}

}