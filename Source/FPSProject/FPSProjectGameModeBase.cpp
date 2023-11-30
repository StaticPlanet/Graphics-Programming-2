// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPSProjectGameModeBase.h"

void AFPSProjectGameModeBase::StartPlay()
{
	Super::StartPlay();

	ChangeMenuWidget(StartingWidgetClass);

	// Log to Screen
	// C Assert
	check(GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Starting FPS Map")));

	UE_LOG(LogTemp, Warning, TEXT("Starting FPS Map"));
}

void AFPSProjectGameModeBase::ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass)
{
	// Check if there a UI On screen
	// If there is remove it
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// Create a new UI
	// Add to viewport
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UFPSUserWidget>(GetWorld(), NewWidgetClass);
		CurrentWidget->AddToViewport();
	}
}

