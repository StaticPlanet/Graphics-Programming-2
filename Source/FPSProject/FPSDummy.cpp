// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSDummy.h"

// Sets default values
AFPSDummy::AFPSDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
		RootComponent = CollisionComponent;
	}
	
	if (!DummyMesh) 
	{
		DummyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
		DummyMesh->SetupAttachment(CollisionComponent);
	}
}

// Called when the game starts or when spawned
void AFPSDummy::BeginPlay()
{
	
	
}

// Called every frame
void AFPSDummy::Tick(float DeltaTime)
{
	

}

void AFPSDummy::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* FPSProjectile, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSProjectGameModeBase* GameMode = Cast<AFPSProjectGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		GameMode->CurrentWidget->SetScore(1);
	}
}

