// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSUserWidget.h"

void UFPSUserWidget::SetHealthbar(float percentage)
{
	if (!HealthBar) return; //Validating its there

	HealthBar->SetPercent(percentage);
}
