// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NightmareHymnGameMode.h"
#include "NightmareHymnCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANightmareHymnGameMode::ANightmareHymnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_BaseChar"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
