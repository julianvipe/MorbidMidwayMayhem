// Copyright Epic Games, Inc. All Rights Reserved.

#include "MorbidMidwayMayhemGameMode.h"
#include "MorbidMidwayMayhemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMorbidMidwayMayhemGameMode::AMorbidMidwayMayhemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
