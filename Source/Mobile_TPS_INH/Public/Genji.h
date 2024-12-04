// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDefender.h"
#include "Components/SplineComponent.h"
#include "Components/CapsuleComponent.h"
#include "Genji.generated.h"

/**
 * 
 */
UCLASS()
class MOBILE_TPS_INH_API AGenji : public ABaseDefender
{
	GENERATED_BODY()
	
public:
	AGenji();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* hitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineComponent* patrolPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float patrolSpeed = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float distanceAlongSpline = 0;

	UFUNCTION(BlueprintCallable)
	void MoveAlongSpline(float Speed);

	UFUNCTION()
	virtual void OnBeginOverlap(class UPrimitiveComponent* newComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
