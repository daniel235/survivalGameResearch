// Fill out your copyright notice in the Description page of Project Settings.

#include "pickUp.h"


// Sets default values
ApickUp::ApickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

}

// Called when the game starts or when spawned
void ApickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ApickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ApickUp::IsActive() {
	return bIsActive;
}

void ApickUp::SetActive(bool NewPickupState) {
	bIsActive = NewPickupState;
}

void ApickUp::WasCollected_Implementation() {
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}