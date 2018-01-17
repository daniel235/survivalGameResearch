// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "pickUp.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SURVIVAL_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ApickUp> WhatToSpawn;
	FTimerHandle SpawnTimer;

	/* Minimum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	//Maximum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }


	/* Find a random point withing the boxcomponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	//handle spawning a new pickup
	void SpawnPickup();

	/* the current spawn delay*/
	float SpawnDelay;

};
