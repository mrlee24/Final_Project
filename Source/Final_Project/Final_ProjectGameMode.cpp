// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Final_ProjectGameMode.h"
#include "Final_ProjectHUD.h"
#include "Final_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinal_ProjectGameMode::AFinal_ProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFinal_ProjectHUD::StaticClass();
}
