// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "FPDefaultGameState.h"
#include "FPDefaultCharacter.h"
#include "FPGameMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class DT_FINALPROJECT_API UFPGameMainWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	class AFPDefaultGameState* currentState = nullptr;
	class AFPDefaultCharacter* currentCharacter = nullptr;

	UTextBlock* timeTextBlock = nullptr;
	UProgressBar* playerHealthbar = nullptr;
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
};
