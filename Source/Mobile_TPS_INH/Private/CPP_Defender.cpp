// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Defender.h"

// Sets default values
ACPP_Defender::ACPP_Defender()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxHealth = 100.f;
	Health = MaxHealth;
	Damage = 10.f;
	FireRate = 0.3f;
	InvicibilityTime = 3.f;
}

// Called when the game starts or when spawned
void ACPP_Defender::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Defender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


