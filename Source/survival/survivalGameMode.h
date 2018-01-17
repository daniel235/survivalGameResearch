// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "survivalGameMode.generated.h"

UCLASS(minimalapi)
class AsurvivalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AsurvivalGameMode();

	virtual void Tick(float DeltaTime) override;

protected:
	//rate at which the characterer loses power
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float DecayRate;



};



