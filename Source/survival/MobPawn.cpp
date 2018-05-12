// Fill out your copyright notice in the Description page of Project Settings.

#include "MobPawn.h"
#include "math.h"
#include "survivalCharacter.h"
#include "EngineUtils.h"
#include "UObject/UObjectIterator.h"
#include "survivalCharacter.h"
#include "GameFramework/PlayerController.h"
#include "UObject/Object.h"
#include "random"
#include "time.h"



// Sets default values
AMobPawn::AMobPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	pos = GetActorLocation();
	origPos = pos;
	myWorld = this->GetWorld();
	range = this->range;
}

// Called when the game starts or when spawned
void AMobPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMobPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	pursuitLocation = getActor();
	lookForAgent(pursuitLocation);
	
}

// Called to bind functionality to input
void AMobPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//pursuing character
void AMobPawn::lookForAgent(FVector loc)
{
	float x = (loc.X - pos.X);
	float y = (loc.Y - pos.Y);
	float z = (loc.Z - pos.Z);
	//setting path or directional vector
	path.X = x;
	path.Y = y;
	path.Z = z;
	//speed of travel
	float step = 3.0;
	float magnit = magnitude(path);

	//getting the unit vector
	FVector n;
	n = normalize(path, magnit);
	n *= step;
	pos.X += n.X;
	pos.Y += n.Y;
	pos.Z += n.Z;
	SetActorLocation(pos);

}

//magnitude is the distance to end point
float AMobPawn::magnitude(FVector s)
{
	int m;
	m = sqrt((s.X * s.X) + (s.Y * s.Y) + (s.Z * s.Z));
	return m;
}

//getting the unit vector
FVector AMobPawn::normalize(FVector n, float m) {
	FVector ans;
	ans.X = n.X / m;
	ans.Y = n.Y / m;
	ans.Z = n.Z / m;
	return ans;
}

//getting actor location
FVector AMobPawn::getActor() {
	FVector targetLocation;
	FVector MyLocation = GetActorLocation();
	for (TObjectIterator<AsurvivalCharacter> Itr; Itr; ++Itr) {
		AsurvivalCharacter *Component = *Itr;
		targetLocation = Component->GetActorLocation();
		//PlayerInputComponent->ClientMessage(Itr->GetName());
	}
	//UE_LOG(LogClass, Log, TEXT("target location x = %d, y = %d, z = %d"), targetLocation.X, targetLocation.Y, targetLocation.Z);
	//UE_LOG(LogClass, Log, TEXT("bear location x = %d, y = %d, z = %d"), MyLocation.X, MyLocation.Y, MyLocation.Z);
	return targetLocation;
}

bool AMobPawn::InMobRange() {
	FVector enemy = getActor();
	FVector me = origPos;
	FVector loc;
	float po;
	loc.X = enemy.X - me.X;
	loc.Y = enemy.Y - me.Y;
	loc.Z = enemy.Z - me.Z;
	po = magnitude(loc);
	if (po > range) {
		return true;
	}
	else {
		return false;
	}
	
}

bool AMobPawn::leash() {
	FVector loc;
	float po;
	loc.X = pos.X - origPos.X;
	loc.Y = pos.Y - origPos.Y;
	loc.Z = pos.Z - origPos.Y;
	po = magnitude(loc);
	if (po > this->range) {
		UE_LOG(LogClass, Log, TEXT("leashing"));
		return true;
	}
	else {
		UE_LOG(LogClass, Log, TEXT("not leashing"));
		return false;
	}
}

void AMobPawn::patrol() {
	FVector pawnLocation;
	FVector randomLocation;
	float r;
	srand(time(NULL));
	pawnLocation = GetActorLocation();
	randomLocation.X = pawnLocation.X - origPos.X;
	randomLocation.Y = pawnLocation.Y - origPos.Y;
	randomLocation.Z = pawnLocation.Z - origPos.Z;

	r = magnitude(randomLocation);
	if (r > range) {
		pawnLocation.X -= rand() % 20;
		pawnLocation.Y -= rand() % 20;
	}
	else {
		pawnLocation.X += rand() % 20;
		pawnLocation.Y += rand() % 20;
	}
	SetActorLocation(pawnLocation);
	return;
}
