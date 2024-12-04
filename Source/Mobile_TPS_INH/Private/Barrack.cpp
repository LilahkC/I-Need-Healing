// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrack.h"

// Sets default values
ABarrack::ABarrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrack::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ABaseDefender* guard : guardList)
	{
		if (guard->bDead && !GetWorldTimerManager().IsTimerActive(RespawnHandle))
		{
			GetWorldTimerManager().SetTimer(RespawnHandle, [this]() { RespawnFirstDefender(); }, RespawnTime, false);
		}
	}
}


void ABarrack::RespawnFirstDefender()
{
	for (ABaseDefender* guard : guardList)
	{
		if (guard->bDead)
		{
			guard->SetActorLocation(RespawnOffset);
			guard->Health = guard->MaxHealth;
			guard->EnableDefender(true);
		}
	}
}

