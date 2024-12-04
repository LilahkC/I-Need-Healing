// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
AWaveController::AWaveController()
	:WaveCount(5), EnemyNumInGame(0), EmptySpawner(0), WaveInterval(60), RemainingSeconds(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWaveController::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);
	for (AActor* Actor : AllActors)
	{
		AEnemySpawner* EnemySpawner = Cast<AEnemySpawner>(Actor);
		if (EnemySpawner)
		{
			SpawnerList.Add(EnemySpawner);
		}
	}
}

// Called every frame
void AWaveController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RemainingSeconds = GetWorldTimerManager().GetTimerRemaining(TimerHandle_DelayedFunction);
	UE_LOG(LogTemp, Warning, TEXT("Remaining Time: %f seconds"), RemainingSeconds);
	if (RemainingSeconds < 0)
	{
		RemainingSeconds = WaveInterval;
	}
}

void AWaveController::UpdateEnemyCount(int32 life)
{
	EnemyNumInGame += life;
}

void AWaveController::CheckEnemySpawner()
{
	EmptySpawner++;

	if (EmptySpawner == SpawnerList.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("All Spawners are empty"));
		// Delay to spawn new enemy
		GetWorldTimerManager().SetTimer( TimerHandle_DelayedFunction, this, &AWaveController::ResetEnenmySpawner, WaveInterval, true);
	}
}

void AWaveController::ResetEnenmySpawner()
{
	EmptySpawner = 0;
	for (AEnemySpawner* Spawner : SpawnerList)
	{
		if (WaveCount != 0)
		{
			Spawner->SpawnNum += 3;
			Spawner->bEmpty = false;
			Spawner->SpawnEnemy();
		}
	}
	WaveCount--;
}