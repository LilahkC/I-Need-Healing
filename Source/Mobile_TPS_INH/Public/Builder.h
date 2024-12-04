// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builder.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ABuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Building Types")
	TArray<TSubclassOf<class AActor>> TowerBlueprints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Types")
	int32 BuildIndex;
};
