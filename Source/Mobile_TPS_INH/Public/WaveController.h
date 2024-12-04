// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.h"
#include "WaveController.generated.h"


UCLASS()
class MOBILE_TPS_INH_API AWaveController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Wave Settings")
	int32 WaveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
	int32 EnemyNumInGame;

	UFUNCTION(BlueprintCallable, Category = "Wave fucntion")
	void UpdateEnemyCount(int32 life);

	UFUNCTION(BlueprintCallable, Category = "Wave function")
	void CheckEnemySpawner();

	UPROPERTY(EditAnywhere, Category = "Wave Settings")
	TArray<AEnemySpawner*> SpawnerList;

	UFUNCTION(BlueprintCallable, Category = "Wave function")
	void ResetEnenmySpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
	FTimerHandle TimerHandle_DelayedFunction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
	int32 RemainingSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
	float WaveInterval;

private:
	int32 EmptySpawner;
};