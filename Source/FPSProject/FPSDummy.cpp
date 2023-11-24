// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSDummy.h"

// Sets default values
AFPSDummy::AFPSDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DummyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
}

// Called when the game starts or when spawned
void AFPSDummy::BeginPlay()
{
	
	
}

// Called every frame
void AFPSDummy::Tick(float DeltaTime)
{
	

}

