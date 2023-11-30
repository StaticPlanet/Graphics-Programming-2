// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "FPSUserWidget.h"
#include "FPSProjectGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class FPSPROJECT_API AFPSProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG UI")
		TSubclassOf<UFPSUserWidget> StartingWidgetClass;

	UPROPERTY()
		UFPSUserWidget* CurrentWidget;

	UFUNCTION(BlueprintCallable, Category = "UMG UI")
		void ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass);
};