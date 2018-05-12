// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MobPawn.h"
#include "Components/ActorComponent.h"
#include "behavior.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API Ubehavior : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Ubehavior();
	Ubehavior(AMobPawn &animal);
	AMobPawn *body;
	FVector bodyLocation;
	FVector2D randomLocation;
	int status;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void patrol(FVector2D anchor);
	void attack(AMobPawn& target);
	void move(FVector2D location);

		
	
};
