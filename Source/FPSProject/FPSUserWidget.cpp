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
}

void UFPSUserWidget::SetScore(int scoreAmount)
{
	if (!ScoreText) return;

	UIScore += scoreAmount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
