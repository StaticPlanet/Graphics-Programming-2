// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "FPSProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
		UButton* Play;

	UPROPERTY(meta = (BindWidget))
		UButton* Quit;

	UFUNCTION()
		void OnPlayButtonClicked();

	UFUNCTION()
		void OnQuitButtonClicked();
};
