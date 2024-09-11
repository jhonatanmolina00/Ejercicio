// Copyright Epic Games, Inc. All Rights Reserved.

#include "EjercicioGameMode.h"
#include "EjercicioCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEjercicioGameMode::AEjercicioGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

	