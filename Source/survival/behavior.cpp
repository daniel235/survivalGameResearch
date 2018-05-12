// Fill out your copyright notice in the Description page of Project Settings.

#include "behavior.h"
#include "GameFramework/Pawn.h"

#include "random"
#include "time.h"


// Sets default values for this component's properties

Ubehavior::Ubehavior() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

Ubehavior::Ubehavior(AMobPawn& animal)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	body = &animal;
	status = 0;
	// ...
}


// Called when the game starts
void Ubehavior::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Ubehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	bodyLocation = body->GetActorLocation();
}


void Ubehavior::patrol(FVector2D anchor) {
	//initialize behavior

	//patroling to random location once finished get another random location
	//need to check if it is in range
	if (status != 1) {
		srand(time(NULL));
		//get random location
		randomLocation.X = bodyLocation.X += rand() % 100;
		randomLocation.Y = bodyLocation.Y += rand() % 100;
		if (!body->leash()) {
			move(randomLocation);
			status = 1;
		}
	}
}

void Ubehavior::attack(AMobPawn& target) {
	//initialize behavior
	if (status != 1) {
		AMobPawn* t;
		t = &target;
	}
	
}

void Ubehavior::move(FVector2D location) {
	//initialize behavior
	if (status != 1) {
		//start move
		//get magnitude 

	}
}