// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDefender.h"
#include <vector>
#include "Barrack.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ABarrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RespawnTime = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ABaseDefender*> guardList;

	FTimerHandle RespawnHandle;
	FDelegateHandle RespawnDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RespawnOffset;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void RespawnFirstDefender();
};
