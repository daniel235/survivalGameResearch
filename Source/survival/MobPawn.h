// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MobPawn.generated.h"

UCLASS()
class SURVIVAL_API AMobPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMobPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//entity properties
	int range;
	float hp, attackPower;

	//logistics
	FVector pos;
	FVector origPos;
	FVector pursuitLocation;
	FVector path;
	UWorld *myWorld;

	//functions 
	void lookForAgent(FVector loc);
	float magnitude(FVector s);
	FVector normalize(FVector n, float m);
	FVector getActor();
	bool leash();
	bool InMobRange();

};
