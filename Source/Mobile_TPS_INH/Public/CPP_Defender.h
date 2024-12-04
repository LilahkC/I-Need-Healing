// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseDefender.h"
#include "CPP_ControlPoint.h"
#include "CPP_Defender.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ACPP_Defender : public ABaseDefender
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Defender();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACPP_ControlPoint* PointToDefend;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
