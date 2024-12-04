// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UFUNCTION(BlueprintCallable)
	void BecomeInvincible(float duration);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle InvicibilityHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InvicibilityTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlinkDuration = 0.2f;

	bool bInvincible = false;

	bool bCanShoot = false;

	FTimerHandle BlinkHandle;

	FTimerHandle FireRateHandle;

	UFUNCTION(BlueprintCallable)
	bool TryFire();

	UFUNCTION()
	virtual float TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
