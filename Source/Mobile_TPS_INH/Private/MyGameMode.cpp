// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "GameInfos.h"

int32 AMyGameMode::GetCurrentGold()
{
	return GameInfos::GetGameInfos().GetCurrentGolds();
}

int32 AMyGameMode::GetWaves()
{
	return GameInfos::GetGameInfos().GetWaves();
}
