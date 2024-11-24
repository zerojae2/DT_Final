// Fill out your copyright notice in the Description page of Project Settings.


#include "FPMainLevelScriptActor.h"
#include "FPMainWidget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AFPMainLevelScriptActor::BeginPlay() 
{
	Super::BeginPlay();

	if (IsValid(MainWidget))
	{
		if (UFPMainWidget* created = CastChecked<UFPMainWidget>(CreateWidget(GetWorld(), MainWidget)))
		{
			created->AddToPlayerScreen();
		};
	};

	if (APlayerController* player = UGameplayStatics::GetPlayerController(GetWorld(), 0)) 
	{
		player->SetShowMouseCursor(true);


		FInputModeGameAndUI inputMode;
		inputMode.SetHideCursorDuringCapture(false);
		player->SetInputMode(inputMode);
	}
}

