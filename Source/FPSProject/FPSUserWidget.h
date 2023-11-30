// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Progressbar.h"
#include "Blueprint/UserWidget.h"
#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UFUNCTION()
		void SetHealthbar(float percentage);


};
