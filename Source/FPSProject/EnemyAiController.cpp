// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAiController.h"

AEnemyAiController::AEnemyAiController()
{
	if (!PawnSensing) {
		PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
	}
}

void AEnemyAiController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAiController::OnSeePawn);
}

void AEnemyAiController::OnSeePawn(APawn* PlayerPawn)
{
	AFPSCharacter* player = Cast<AFPSCharacter>(PlayerPawn);

	if (!player) return;

	SetCanSeePlayer(true, player);
	RunTriggerableTimer();
}

void AEnemyAiController::SetCanSeePlayer(bool SeePlayer, UObject* Player)
{
	UBlackboardComponent* bb = GetBlackboardComponent();
	bb->SetValueAsBool(FName("CanSeePlayer"), SeePlayer);
	if (SeePlayer) {
		bb->SetValueAsObject(FName("PlayerTarget"), Player);
	}
}

void AEnemyAiController::RunTriggerableTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(RetriggerableTimerHandle);
	FunctionDelegate.BindUFunction(this, FName("SetCanSeePlayer"), false, GetPawn());
	GetWorld()->GetTimerManager().SetTimer(RetriggerableTimerHandle, FunctionDelegate, PawnSensing->SensingInterval * 2.0f, false);
}


