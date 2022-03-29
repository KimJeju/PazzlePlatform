// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzlePlatFormsGameMode.h"
#include "PuzzlePlatFormsCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzlePlatFormsGameMode::APuzzlePlatFormsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
