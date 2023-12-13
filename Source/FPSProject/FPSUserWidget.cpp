// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	SetHealthbar(1.0);
	SetScore(0);
}

void UFPSUserWidget::SetHealthbar(float percentage)
{
	if (!HealthBar) return; //Validating its there

	HealthBar->SetPercent(percentage);

	if (percentage == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Game is Over"));

	}
}

void UFPSUserWidget::SetScore(int scoreAmount)
{
	if (!ScoreText) return;

	UIScore += scoreAmount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
