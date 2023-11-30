// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API ACoin : public APickUp
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float RotationRate = 100;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float CollectRotationRate = 1500;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;

	FTimerHandle DeathTimerHandle;
	void DeathTimerComplete();
};


