// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ControlPoint.h"
#include "CPP_Player.h"
#include "CPP_Defender.h"
#include "EnemyBase.h"


// Sets default values
ACPP_ControlPoint::ACPP_ControlPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ControlCollision = CreateDefaultSubobject<USphereComponent>(FName("Control Point Collision"));
	ControlCollision->SetSphereRadius(300.0f);
	ControlCollision->SetGenerateOverlapEvents(true);
	ControlCollision->SetupAttachment(RootComponent);
	ControlCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	ControlCollision->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void ACPP_ControlPoint::BeginPlay()
{
	Super::BeginPlay();

	ControlCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_ControlPoint::OnBeginOverlap);
	ControlCollision->OnComponentEndOverlap.AddDynamic(this, &ACPP_ControlPoint::OnEndOverlap);

}

void ACPP_ControlPoint::OnBeginOverlap(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	actorsInside.push_back(OtherActor);
}

void ACPP_ControlPoint::OnEndOverlap(UPrimitiveComponent* overlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	actorsInside.erase(std::remove(actorsInside.begin(), actorsInside.end(), OtherActor), actorsInside.end());
}

void ACPP_ControlPoint::Capture()
{
	for (size_t i = 0; i < actorsInside.size(); i++)
	{
		//const ACPP_Player* player =
		if (Cast<ACPP_Player>(actorsInside.at(i)))
		{
			controlPercent += captureRatePlayer / GetWorld()->GetTimeSeconds();
		}
		else if (Cast<ACPP_Defender>(actorsInside.at(i)))
		{
			controlPercent += captureRateAllies / GetWorld()->GetTimeSeconds();
		}
		else if (Cast<AEnemyBase>(actorsInside.at(i)))
		{
			controlPercent += captureRateEnemies / GetWorld()->GetTimeSeconds();
		}
	}

	controlPercent = FMath::Clamp(controlPercent, 0, 1);
}

// Called every frame
void ACPP_ControlPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawCircle(GetWorld(), GetActorLocation(), GetActorRightVector(), GetActorForwardVector(), FMath::Lerp(colorEnemies, colorAllies, controlPercent).ToFColor(true), ControlCollision->GetScaledSphereRadius(), 50, false, 0.f, (uint8)0U, 5);

	if (!actorsInside.empty())
		Capture();
	
}