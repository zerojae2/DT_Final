// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalProjectDefaultController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework//Pawn.h"
#include "FPPauseWidget.h"

void AFinalProjectDefaultController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);

	};

	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
};

void AFinalProjectDefaultController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFinalProjectDefaultController::InputMove);
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &AFinalProjectDefaultController::InputPause);
	}
};

void AFinalProjectDefaultController::InputMove(const FInputActionValue& value) 
{
	FVector2D inputAxis = value.Get<FVector2D>();

	if (ACharacter* controlledCharacter = GetCharacter()) 
	{
		controlledCharacter->GetMovementComponent()->AddInputVector(FVector(inputAxis.Y, inputAxis.X, 0));
	}
}

void AFinalProjectDefaultController::InputPause() 
{
	//SetPause(IsPaused() == false);
	if (IsValid(PauseWidget)) 
	{
		if (IsValid(currentPause)) 
		{
			currentPause->RemoveFromParent();
			currentPause = nullptr;
		}
		else if (currentPause = CreateWidget(this, PauseWidget))
		{
			currentPause->AddToPlayerScreen(0);
		}
	}
}

