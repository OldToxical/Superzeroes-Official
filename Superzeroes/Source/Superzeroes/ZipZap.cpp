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
	ComboAttack_Savage_ExecutionTimer = 10.0f;
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
	//if zip zap is attacking, check the hitbox for collision 
	if (characterState == State2::Attacking)
	{
		HitCheck();
	}
}

void AZipZap::UpdateAnimation()
{
	// If character is moving, change to running animation
	if (charMove->Velocity.X != 0.f)
	{
		if (characterState != State2::Combo_Savage && characterState != State2::Attacking)
		{
			characterState = State2::Running;
			flipbook->SetFlipbook(run);

			//If character is jumping, change to jump animation
			//if (charMove->IsFalling())
			//{
			//	characterState = State::Jumping;
			//	flipbook->SetFlipbook(jumping);
			//}
		}
	}
	else // Otherwise, change to idle animation
	{
		if (characterState != State2::Attacking && characterState != State2::Jumping)
		{
			characterState = State2::Idle;
			flipbook->SetFlipbook(idle);
		}
	}
}

void AZipZap::move(float scaleVal)
{
	// Add movement force only if the character is not in a state of savage attack
	if (characterState != State2::Combo_Savage)
	{
		characterSpeed = 350.f;
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), scaleVal, false);
	}

	// Determine the character's facing direction, regardless of the state
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

void AZipZap::InitiateComboAttack_Savage()
{
	if (boomBoom != NULL)
	{
		float proximityToBoomBoom = abs(boomBoom->GetActorLocation().X - GetActorLocation().X);

		if (proximityToBoomBoom <= MaximumDistanceBetweenPlayersForInitiatingSavageComboAttack)
		{
			boomBoom->InitiateComboAttack_Savage(rotation.Yaw);
			flipbook->SetLooping(false);
			flipbook->SetFlipbook(initiateBoomBoomSavageComboAttack);
		}
	}
}

void AZipZap::SetupPlayerInput(UInputComponent* input_)
{
	Input = input_;

	Input->BindAxis("MoveZipZap", this, &AZipZap::move);
	Input->BindAxis("AttackZipZap", this, &AZipZap::Attack);
	Input->BindAction("JumpZipZap", IE_Pressed, this, &AZipZap::ExecuteJump);
	Input->BindAction("InitiateComboAttack_Savage", IE_Pressed, this, &AZipZap::InitiateComboAttack_Savage);
}

void AZipZap::Attack(float scaleVal)
{
	// Allow the execution of the simple attack only if the character is not in a state of savage attack
	if (characterState != State2::Combo_Savage)
	{
		// If the attack button is pressed (or held), keep track of how long the user is holding the button down
		if (scaleVal > 0.f)
		{
			// Whatever the length is, change the state to "attacking"
			characterState = State2::Attacking;

			// Increase the time the button has been held down
			attackInputTimer += GetWorld()->GetDeltaSeconds();

			// If the user is holding the button for too long, change the state of the character to "charging". From this point on, a strong attack will be executed once the button is released
			if (attackInputTimer > StrongAttackMinimumInputTime)
			{
				flipbook->SetFlipbook(strongAttackCharge);
			}
		}
		else // The button is not pressed. If the value of "attackInputTimer" is bigger than 0.f, this means the button was released during the current iteration, so let's determine what attack to execute
		{
			// Simple attack
			if (attackInputTimer > 0.f && attackInputTimer < StrongAttackMinimumInputTime)
			{
				// Set the corresponding animation to execute and set the flipbook's property of looping to false, since we want the animation to execute only once
				flipbook->SetLooping(false);
				flipbook->SetFlipbook(simpleAttack);
			}
			else if (attackInputTimer >= StrongAttackMinimumInputTime) // Strong attack
			{
				characterState = State2::Charge_Attacking;
				// Set the corresponding animation to execute and set the flipbook's property of looping to false, since we want the animation to execute only once
				flipbook->SetLooping(false);
				flipbook->SetFlipbook(strongAttack);
			}

			// Reset the timer, doesn't matter if the button was released or wasn't pressed at all during this iteration, it's currently not pressed.
			attackInputTimer = 0.f;
		}
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
}

void AZipZap::ExecuteJump()
{
	if ((characterState != State2::Combo_Savage) && (characterState != State2::Attacking) && !charMove->IsFalling())
	{
		Jump();
		characterState = State2::Jumping;
		flipbook->SetLooping(false);
		flipbook->SetFlipbook(jumping);
	}
}

void AZipZap::HitCheck()
{	//get if Boom Boom is overlapping with the attack hitbox
	TArray<AActor*> output;
	GetOverlappingActors(output, ABoomBoom::StaticClass());
	//go through each overlapping body
	for (int i = 0; i < output.Num(); i++)
	{
		ABoomBoom* bb;
		bb = (ABoomBoom*)UGameplayStatics::GetActorOfClass(GetWorld(), ABoomBoom::StaticClass());
		bb->InitiateComboAttack_Savage(0.0f);
	}
}

void AZipZap::UpdateComboAttack_Savage()
{
	// The length of the attack is finite, decrease the timer that keeps of this each iteration
	ComboAttack_Savage_ExecutionTimer -= GetWorld()->GetDeltaSeconds();

	//Do we want Zip Zap to do anything during this combo attack? Commented it out just in case

	// There is still time to be executed
	/*if (ComboAttack_Savage_ExecutionTimer > 0.f)
	{
		if (flipbook->GetComponentRotation().Yaw < 180.f) // The user wants Boom Boom to run right
		{
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.f, false);
		}
		else // The user wants Boom Boom to run left
		{
			AddMovementInput(FVector(-1.0f, 0.0f, 0.0f), 1.f, false);
		}
	}
	else // There's no more time, end the savage attack
	{
		ComboAttack_Savage_ExecutionTimer = SavageComboExecutionTime;
		characterState = State2::Idle;
	}*/
}