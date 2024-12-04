// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "TowerBase.generated.h"

UENUM(BlueprintType)
enum class ETowerType : uint8
{
	CrossBowTower UMETA(DisplayName = "CrossBow Tower"),
	GunTower UMETA(DisplayName = "Gun Tower"),
	MageTower UMETA(DisplayName = "Mage Tower")
};

UCLASS()
class MOBILE_TPS_INH_API ATowerBase : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaming Data")
	AActor* AlineBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Setting")
	int32 Cost;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaming Data")
	TArray<TSubclassOf<AActor>> EnemyClassesToTrack;
	
	UFUNCTION(BlueprintCallable, Category = "Tower Settings")
	void GetTowerCost(ETowerType TowerType);

	UFUNCTION(BlueprintCallable, Category = "Tower Settings")
	void TakeGold(int32 ThisCost);
};
