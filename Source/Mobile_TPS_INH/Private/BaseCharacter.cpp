// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ABaseCharacter::TryFire()
{
	if (GetWorldTimerManager().IsTimerActive(FireRateHandle))
		return false;
		
	bCanShoot = false;
	GetWorldTimerManager().SetTimer(FireRateHandle, [this]() { bCanShoot = true; }, FireRate, false);
	
	return true;
}

float ABaseCharacter::TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bInvincible)
		return 0;

	if (DamageAmount <= 0)
		return DamageAmount;

	BecomeInvincible(InvicibilityTime);

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void ABaseCharacter::BecomeInvincible(float Duration)
{
	bInvincible = true;
	GetWorldTimerManager().SetTimer(InvicibilityHandle, [this]() { bInvincible = false; GetMesh()->SetVisibility(true, true); GetWorldTimerManager().ClearTimer(BlinkHandle); }, Duration, false);
	GetWorldTimerManager().SetTimer(BlinkHandle, [this]() { GetMesh()->SetVisibility(!GetMesh()->IsVisible(), true); }, BlinkDuration, true);
}
