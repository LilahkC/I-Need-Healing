// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MOBILE_TPS_INH_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Game Infos")
	int32 GetCurrentGold();

	UFUNCTION(BlueprintCallable, Category = "Game Infos")
	int32 GetWaves();
};
