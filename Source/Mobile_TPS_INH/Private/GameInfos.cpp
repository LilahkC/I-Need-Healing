// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInfos.h"

GameInfos::GameInfos()
{
	Golds = 2000;
}

GameInfos& GameInfos::GetGameInfos()
{
	static GameInfos GameInfos;
	return GameInfos;
}

void GameInfos::UpdateGolds(int32 GoldNums)
{
	Golds += GoldNums;
}

int32 GameInfos::GetCurrentGolds()
{
	return Golds;
}

int32 GameInfos::GetWaves()
{
	return Waves;
}

GameInfos::~GameInfos()
{
}
