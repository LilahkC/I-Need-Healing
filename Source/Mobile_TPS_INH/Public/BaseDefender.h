// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.h"
#include "BaseDefender.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ABaseDefender : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseDefender();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttackMode = false;

	void EnableDefender(bool Enable);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Attack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
