// Fill out your copyright notice in the Description page of Project Settings.


#include "Genji.h"
#include "Kismet/GameplayStatics.h"
#include "PatrolPath.h"


AGenji::AGenji()
{
	MaxHealth = 100.f;
	Health = MaxHealth;
	Damage = 15.f;
	FireRate = 0.2f;
	InvicibilityTime = 3.f;

	hitBox = CreateDefaultSubobject<UCapsuleComponent>(FName("Hitbox"));
	hitBox->SetGenerateOverlapEvents(true);
	hitBox->SetupAttachment(RootComponent);
	hitBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	hitBox->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void AGenji::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPath::StaticClass(), FoundActors);

	if (!FoundActors.IsEmpty())
	{
		//AActor* actor = ;
		//actor->SetActorLocation({ actor->GetActorLocation().X, actor->GetActorLocation().Y, GetActorLocation().Z });
		patrolPath = Cast<APatrolPath>(FoundActors.Pop())->patrolPath;
	}

	hitBox->OnComponentBeginOverlap.AddDynamic(this, &AGenji::OnBeginOverlap);
}

// Called every frame
void AGenji::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGenji::MoveAlongSpline(float Speed)
{
	distanceAlongSpline += Speed;

	FTransform newTransform = patrolPath->GetTransformAtDistanceAlongSpline(distanceAlongSpline, ESplineCoordinateSpace::World);
	newTransform.SetScale3D(GetActorScale3D());
	if (patrolSpeed < 0)
		newTransform.SetRotation(newTransform.GetRotation().Rotator().Add(0, 180.f, 0).Quaternion());

	newTransform.SetLocation({ newTransform.GetLocation().X,newTransform.GetLocation().Y, GetActorLocation().Z });

	SetActorTransform(newTransform);

	if (distanceAlongSpline >= patrolPath->GetSplineLength() || distanceAlongSpline <= 0)
	{
		if (patrolPath->IsClosedLoop())
			distanceAlongSpline -= distanceAlongSpline;
		else
			patrolSpeed = -patrolSpeed;
	}
}

void AGenji::OnBeginOverlap(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TSubclassOf <UDamageType> DamageType; // ...use your own Damage Type

	UGameplayStatics::ApplyDamage(OtherActor, Damage,this->Controller ,this, DamageType);

}