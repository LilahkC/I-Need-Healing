// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include <vector>
#include "CPP_ControlPoint.generated.h"

UCLASS()
class MOBILE_TPS_INH_API ACPP_ControlPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_ControlPoint();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* ControlCollision;

	UFUNCTION()
	virtual void OnBeginOverlap(class UPrimitiveComponent* newComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* overlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor colorAllies = FLinearColor::Blue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor colorEnemies = FLinearColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float controlPercent = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float captureRateAllies = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float captureRateEnemies = -0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float captureRatePlayer = 0.33f;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	std::vector<AActor*> actorsInside;

	void Capture();

};
