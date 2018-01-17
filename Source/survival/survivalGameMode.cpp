// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "survivalGameMode.h"
#include "survivalCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "survivalCharacter.h"
#include "Kismet/GameplayStatics.h"

AsurvivalGameMode::AsurvivalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//base decay
	DecayRate = 0.01f;


}

void AsurvivalGameMode::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AsurvivalCharacter* MyCharacter = Cast<AsurvivalCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter) {
		if (MyCharacter->GetCurrentPower() > 0) {
			MyCharacter->UpdatePower(-DeltaTime*DecayRate*(MyCharacter->GetInitialPower()));
		}
		
	}

}
