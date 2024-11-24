// Fill out your copyright notice in the Description page of Project Settings.


#include "FPGameMainWidget.h"


void UFPGameMainWidget::NativeConstruct() 
{
	Super::NativeConstruct();
	timeTextBlock = CastChecked<UTextBlock>(GetWidgetFromName(TEXT("TimeTextBlock")));
	playerHealthbar = CastChecked<UProgressBar>(GetWidgetFromName(TEXT("Healthbar")));
}

void UFPGameMainWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime) 
{
	Super::NativeTick(MyGeometry, DeltaTime);
	if (IsValid(timeTextBlock) && IsValid(currentState)) 
	{
		timeTextBlock->SetText(FText::FromString(currentState->GetTimeString()));
	}

	if (IsValid(playerHealthbar) && IsValid(currentCharacter)) 
	{
		playerHealthbar->SetPercent(currentCharacter->GetHealthRate());
	}
}
