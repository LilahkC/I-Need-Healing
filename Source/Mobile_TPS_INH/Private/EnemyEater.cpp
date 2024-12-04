// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyEater.h"
#include "GameInfos.h"

// Sets default values
AEnemyEater::AEnemyEater()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BonusGold = 10;
}

// Called when the game starts or when spawned
void AEnemyEater::BeginPlay()
{
	Super::BeginPlay();
	MaxHealth = 200;
	Health = MaxHealth;
}

// Called every frame
void AEnemyEater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyEater::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}