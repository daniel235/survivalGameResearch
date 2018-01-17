// Fill out your copyright notice in the Description page of Project Settings.

#include "berryPickup.h"
#include "pickUp.h"
#include "Components/StaticMeshComponent.h"

AberryPickup::AberryPickup() {
	GetMesh()->SetSimulatePhysics(true);

	//the base power level of the battery
	BatteryPower = 150.f;
}

void AberryPickup::WasCollected_Implementation() {
	//use the base behavior
	Super::WasCollected_Implementation();
	//destroy the battery
	Destroy();
}

float AberryPickup::GetPower() {
	return BatteryPower;
}


