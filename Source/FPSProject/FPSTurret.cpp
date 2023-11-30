// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSTurret.h"
#include "Kismet/KismetMathLibrary.h"
#include "TurretAnimInterFace.h"

#define OUT
// Sets default values
AFPSTurret::AFPSTurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Root and add to Viewport
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//Create Skeletal mesh and add to Viewport
	TurretMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(Root);

	//Create Static mesh and add to Viewport
	Beam = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beam"));
	//Attaching to socket
	Beam->SetupAttachment(TurretMesh,TEXT("Beam"));

	Target1 = CreateDefaultSubobject<USceneComponent>(TEXT("Target1"));
	Target1->SetupAttachment(Root);

	Target2 = CreateDefaultSubobject<USceneComponent>(TEXT("Target2"));
	Target2->SetupAttachment(Root);

	FollowTarget = CreateDefaultSubobject<USceneComponent>(TEXT("FollowTarget"));
	FollowTarget->SetupAttachment(Root);


}

// Called when the game starts or when spawned
void AFPSTurret::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFPSTurret::ChangeBeamTarget,ChangeTargetDelay,true,1.f);
}

// Called every frame
void AFPSTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLookAtTarget(DeltaTime);
	TraceBeam();
}

void AFPSTurret::UpdateLookAtTarget(float DeltaTime)
{

	if (LookRotation.Equals(TargetRotation, 1.f)) 
	{
		return;
	}

	LookRotation += RotationDelta * RotationRateMultiplyer * DeltaTime;

	if (TurretMesh->GetAnimInstance()->Implements<UTurretAnimInterFace>())
	{
		ITurretAnimInterFace::Execute_UpdateLookAtRotation(TurretMesh->GetAnimInstance(), LookRotation);
	}


}

void AFPSTurret::ChangeBeamTarget()
{
	TimerCount++;

	if (TimerCount%2 == 0) 
	{
		FollowTarget->SetWorldLocation(Target1->GetComponentLocation());
	}
	else
	{
		FollowTarget->SetWorldLocation(Target2->GetComponentLocation());
	}

	FVector Start = TurretMesh->GetSocketLocation("Beam");
	FVector End = FollowTarget->GetComponentLocation();
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

	RotationDelta = TargetRotation - LookRotation;
	RotationDelta.Normalize();
}

void AFPSTurret::SetBeamLength(float Length)
{
	Beam->SetRelativeScale3D(FVector(Length / 400, Beam->GetRelativeScale3D().Y, Beam->GetRelativeScale3D().Z));
	Beam->SetRelativeLocation(FVector(Length / (-8), 0, 0));
}

void AFPSTurret::TraceBeam()
{
	FHitResult HitResult;

	FVector Start = TurretMesh->GetSocketLocation("Beam");
	FVector End = Start + Beam->GetForwardVector() * BeamLength;

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel
	(
		OUT HitResult,
		Start,
		End,
		ECollisionChannel::ECC_Camera,
		CollisionQueryParams
	);

	if (bHit) 
	{
		SetBeamLength(HitResult.Distance);
	}
	else
	{
		SetBeamLength(BeamLength);
	}

}
