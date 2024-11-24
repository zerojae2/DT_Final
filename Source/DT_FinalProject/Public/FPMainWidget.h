// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class DT_FINALPROJECT_API UFPMainWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	class UButton* GameStartButton = nullptr;
	class UButton* GameQuitButton = nullptr;
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void GameStartClicked();
	UFUNCTION()
	virtual void GameQuitClicked();
};
