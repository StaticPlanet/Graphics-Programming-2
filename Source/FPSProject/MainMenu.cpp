// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

void UMainMenu::OnPlayButtonClicked()
{
	AFPSProjectGameModeBase* GameMode = Cast<AFPSProjectGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	GameMode->CurrentWidget->AddToViewport();
}

void UMainMenu::OnQuitButtonClicked()
{
}
