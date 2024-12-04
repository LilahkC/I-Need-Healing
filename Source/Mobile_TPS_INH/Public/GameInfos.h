// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class MOBILE_TPS_INH_API GameInfos
{
public:
	static GameInfos& GetGameInfos();

	void UpdateGolds(int32 GoldNums);

	UFUNCTION(BlueprintCallable, Category = "Game Infos")
	int32 GetCurrentGolds();
	int32 GetWaves();
	~GameInfos();
private:
	GameInfos();

	int32 Golds;
	int32 Waves;
};
