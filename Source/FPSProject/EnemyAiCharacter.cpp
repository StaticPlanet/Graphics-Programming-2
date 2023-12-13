// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAiCharacter.h"

// Sets default values
AEnemyAiCharacter::AEnemyAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyAiCharacter::BeginOverlap);
		CollisionComponent->InitSphereRadius(50.0f);
		RootComponent = CollisionComponent;
	}
}

// Called when the game starts or when spawned
void AEnemyAiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAiCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* FPSCharacter, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSProjectGameModeBase* GameMode = Cast<AFPSProjectGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		Health -= 5;
		float healthPercent = Health / MaxHealth;

		//Casting to game modes widgit
		GameMode->CurrentWidget->SetHealthbar(healthPercent);
	}
}

