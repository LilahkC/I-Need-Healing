// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WaveController.h"
#include "EnemyBase.generated.h"

UCLASS()
class MOBILE_TPS_INH_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	float AttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	int32 BonusGold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	AActor* TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	FVector OriginalTargetPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	TArray<TSubclassOf<AActor>> SenceActorList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Data")
	UCapsuleComponent* EnemyCapsuleComponent;

private:

	UFUNCTION(BlueprintCallable, Category = "Enemy Action")
	void GetBonusGold();

	UFUNCTION(BlueprintCallable, Category = "Enemy Action")
	void BasicAttack();

	UFUNCTION(BlueprintCallable, Category = "Enemy Action")
	virtual void Die();

protected:
	UPROPERTY(EditAnywhere, Category = "Wave")
	AWaveController* WaveController;
};
