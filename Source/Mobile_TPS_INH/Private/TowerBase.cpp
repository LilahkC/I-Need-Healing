// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBase.h"
#include "GameInfos.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ATowerBase::ATowerBase()
	:Cost(100), AttackSpeed(1), AttackRange(2000), Priority(1)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("Tower");
}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerBase::GetTowerCost(ETowerType TowerType)
{
	switch (TowerType)
	{
	case ETowerType::CrossBowTower:
		Cost = 150;
	case ETowerType::GunTower:
		Cost = 300;
	case ETowerType::MageTower:
		Cost = 200;
	default:
		return;
	}
}

void ATowerBase::TakeGold(int32 ThisCost)
{
	GameInfos::GetGameInfos().UpdateGolds(-ThisCost);
}

