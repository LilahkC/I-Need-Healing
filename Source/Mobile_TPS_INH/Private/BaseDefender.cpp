// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDefender.h"

// Sets default values
ABaseDefender::ABaseDefender()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("Player");
}

// Called when the game starts or when spawned
void ABaseDefender::BeginPlay()
{
	Super::BeginPlay();
	Tags.Add("Player");
}

void ABaseDefender::Attack()
{
}

// Called every frame
void ABaseDefender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
		EnableDefender(false);
}

void ABaseDefender::EnableDefender(bool Enable)
{
	bDead = !Enable;

	// Hides visible components
	SetActorHiddenInGame(!Enable);

	// Disables collision components
	SetActorEnableCollision(Enable);

	// Stops the Actor from ticking
	SetActorTickEnabled(Enable);
}

