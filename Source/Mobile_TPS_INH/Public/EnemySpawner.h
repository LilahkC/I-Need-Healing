// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class MOBILE_TPS_INH_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	class UStaticMeshComponent* SpawnPointMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	FVector SpawnPointOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	FRotator SpawnPointRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	int32 SpawnNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	bool bEmpty;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnEnemy();

private:
	// Class of the enemy to spawn
	UPROPERTY(EditAnywhere, Category = "Enemy Generator")
	TSubclassOf<class AEnemyBase> EnemyClass;

	// Spawn interval in seconds
	UPROPERTY(EditAnywhere, Category = "Enemy Generator")
	float SpawnInterval;

	// Timer handle for spawning enemies
	FTimerHandle SpawnTimerHandle;
};
