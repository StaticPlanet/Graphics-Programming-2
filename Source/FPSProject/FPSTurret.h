// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "FPSTurret.generated.h"

UCLASS()
class FPSPROJECT_API AFPSTurret : public AActor
{
	GENERATED_BODY()

private:
	//Root
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	//Skeletal Mesh
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* TurretMesh;

	//Static Mesh
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Beam;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Target1;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Target2;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* FollowTarget;

	UPROPERTY()
		FTimerHandle TimerHandle;

	int TimerCount = 0;
	FRotator LookRotation;
	FRotator TargetRotation;
	FRotator RotationDelta;

	UPROPERTY(VisibleAnywhere)
		float ChangeTargetDelay = 5.f;

	UPROPERTY(VisibleAnywhere)
		float RotationRateMultiplyer = 1.f;

	UFUNCTION()
		void UpdateLookAtTarget(float DeltaTime);

	UFUNCTION()
		void ChangeBeamTarget();


	UFUNCTION(BlueprintCallable)
		void SetBeamLength(float Length);

	UFUNCTION()
		void TraceBeam();

public:	
	// Sets default values for this actor's properties
	AFPSTurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float BeamLength = 200.f;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
