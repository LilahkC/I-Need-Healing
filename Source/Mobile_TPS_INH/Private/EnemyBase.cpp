// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "WaveController.h"
#include "Kismet/GameplayStatics.h"
#include "GameInfos.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    EnemyCapsuleComponent = GetCapsuleComponent();
    if (EnemyCapsuleComponent)
    {
        // Modify collision presets
        EnemyCapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        EnemyCapsuleComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
        EnemyCapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
        EnemyCapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Block);
        EnemyCapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECR_Block);
        //EnemyCapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECR_Block);
    }
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

    WaveController = Cast<AWaveController>(UGameplayStatics::GetActorOfClass(GetWorld(), AWaveController::StaticClass()));

    if (WaveController)
    {
        WaveController->UpdateEnemyCount(1);
    }
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::GetBonusGold()
{
    GameInfos::GetGameInfos().UpdateGolds(BonusGold);
}

void AEnemyBase::BasicAttack()
{
}

void AEnemyBase::Die()
{
    WaveController->UpdateEnemyCount(-1);
    GetBonusGold();
    UE_LOG(LogTemp, Warning, TEXT("My Golds: %d"), GameInfos::GetGameInfos().GetCurrentGolds());
    Destroy();
}

