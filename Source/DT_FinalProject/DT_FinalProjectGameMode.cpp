// Copyright Epic Games, Inc. All Rights Reserved.

#include "DT_FinalProjectGameMode.h"
#include "DT_FinalProjectPlayerController.h"
#include "DT_FinalProjectCharacter.h"
#include "FPDefaultGameState.h"
#include "UObject/ConstructorHelpers.h"


ADT_FinalProjectGameMode::ADT_FinalProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADT_FinalProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/BP_DefultController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	GameStateClass = AFPDefaultGameState::StaticClass();
}