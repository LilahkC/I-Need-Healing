// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Kismet/GameplayStatics.h"
#include "WaveController.h"
#include "EnemyBase.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
    :SpawnInterval(1.0f), SpawnNum(10)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::SpawnEnemy()
{
    if (EnemyClass && SpawnNum)
    {
        // Get the spawn location
        FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f), 0.0f);

        // Get the spawn rotation
        FRotator SpawnRotation = FRotator::ZeroRotator;

        // Spawn the enemy
        AEnemyBase* NewEnemy = GetWorld()->SpawnActor<AEnemyBase>(EnemyClass, SpawnLocation, SpawnRotation);

        if (NewEnemy)
        {
            NewEnemy->MaxHealth += 100.f;
            NewEnemy->Health = NewEnemy->MaxHealth;
        }

        SpawnNum--;

        if (SpawnNum == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("This Spawner is empty"));
            AWaveController* WaveController = Cast<AWaveController>(
                UGameplayStatics::GetActorOfClass(GetWorld(), AWaveController::StaticClass())
            );

            if (WaveController)
            {
                WaveController->CheckEnemySpawner();
            }
            bEmpty = true;
        }
    }
}

