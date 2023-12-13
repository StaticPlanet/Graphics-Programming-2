// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackPlayerTask.h"

EBTNodeResult::Type UAttackPlayerTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking Player"));

	return EBTNodeResult::Succeeded;
}
