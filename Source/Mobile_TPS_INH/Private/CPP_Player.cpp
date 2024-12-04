// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Player.h"
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ACPP_Player::ACPP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActivePlayerController = UGameplayStatics::GetPlayerController(this, 0);
}

// Called when the game starts or when spawned
void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();
	TimeRef = &GetWorldTimerManager();
	if (ActivePlayerController)
	{
		//Input mapping 
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ActivePlayerController->GetLocalPlayer()))
		{
			subsystem->AddMappingContext(MappingContext, 0);
		}
		ActivePlayerController->SetShowMouseCursor(true);
		//Set input mode to game only
		ActivePlayerController->SetInputMode(m_InputMode);
		UGameplayStatics::SetViewportMouseCaptureMode(this, EMouseCaptureMode::CapturePermanently_IncludingInitialMouseDown);
	}
}

// Called every frame
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HealTimer();
}

// Called to bind functionality to input
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(KeyboardAction, ETriggerEvent::Triggered, this, &ACPP_Player::MovePlayer);
		EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ACPP_Player::MoveCamera);
		EnhancedInputComponent->BindAction(SpellAction, ETriggerEvent::Completed, this, &ACPP_Player::Spell);
	}
}

void ACPP_Player::MoveCamera(const FInputActionValue& Value)
{
	FVector2D inputValue = Value.Get<FVector2D>();
	inputValue /= 3;

	AddControllerYawInput(inputValue.X);
	AddControllerPitchInput(inputValue.Y);

	APlayerCameraManager* cameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	cameraManager->ViewPitchMin = -30;
	cameraManager->ViewPitchMax = 40;
}

void ACPP_Player::MovePlayer(const FInputActionValue& Value)
{
	FVector2D inputValue = Value.Get<FVector2D>();
	if (inputValue != FVector2D::Zero())	
	{
		FRotator controlRotation = GetControlRotation();
		FRotator xzRotation = FRotator(0, controlRotation.Yaw, controlRotation.Roll);
		AddMovementInput(UKismetMathLibrary::GetRightVector(controlRotation), inputValue.X);
		AddMovementInput(UKismetMathLibrary::GetForwardVector(xzRotation), inputValue.Y);
	}
}

void ACPP_Player::HealPressed()
{
	bShooting = true;
	if (TimeRef->IsTimerPaused(HealTimerHandle))
		TimeRef->UnPauseTimer(HealTimerHandle);

	else if (!TimeRef->IsTimerActive(HealTimerHandle))
		TimeRef->SetTimer(HealTimerHandle, [this]() { SpawnHealingBall(); }, FireRate, true, 0.0f);
}

void ACPP_Player::HealReleased()
{
	bShooting = false;
}

void ACPP_Player::HealTimer()
{
	if (!bShooting && TimeRef->IsTimerActive(HealTimerHandle) && TimeRef->GetTimerRemaining(HealTimerHandle) <= 0.05f)
	{
		TimeRef->PauseTimer(HealTimerHandle);
	}
}

void ACPP_Player::Spell(const FInputActionValue& Value)
{
	if (hasSpell)
	{
		hasSpell = false;
		bUseSpell = true;
		
		SpawnSuzu();
		TimeRef->SetTimer(SpellTimerHandle, [this]() { hasSpell = true; }, SpellCooldown, false);
	}
}