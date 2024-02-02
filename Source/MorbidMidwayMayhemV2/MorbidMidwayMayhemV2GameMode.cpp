// Copyright Epic Games, Inc. All Rights Reserved.

#include "MorbidMidwayMayhemV2GameMode.h"
#include "MorbidMidwayMayhemV2Character.h"
#include "UObject/ConstructorHelpers.h"

AMorbidMidwayMayhemV2GameMode::AMorbidMidwayMayhemV2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
