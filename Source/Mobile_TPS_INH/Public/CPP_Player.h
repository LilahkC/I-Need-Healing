// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "BaseCharacter.h"
#include "CPP_Player.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ACPP_Player : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Player();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpellCooldown; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShooting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseSpell;

	UPROPERTY(BlueprintReadOnly)
	FTimerHandle SpellTimerHandle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CameraAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* KeyboardAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* HealAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SpellAction;

	void MoveCamera(const FInputActionValue& Value);
	void MovePlayer(const FInputActionValue& Value);
	void HealTimer();
	void Spell(const FInputActionValue& Value);
	
	UFUNCTION(BlueprintCallable)
	void HealPressed();
	UFUNCTION(BlueprintCallable)
	void HealReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnHealingBall();
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnSuzu();

private:
	bool hasSpell = true;

	FInputModeGameOnly m_InputMode;

	FTimerManager* TimeRef;
	FTimerHandle HealTimerHandle;

	APlayerController* ActivePlayerController;
};