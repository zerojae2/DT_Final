// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPPauseWidget.generated.h"

/**
 * 
 */
UCLASS()
class DT_FINALPROJECT_API UFPPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	class UButton* ResumeButton = nullptr;
	class UButton* MainButton = nullptr;

protected:
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* StartPauseAnimation;
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	UFUNCTION()
	virtual void OnResumeClicked();
	UFUNCTION()
	virtual void OnMainClicked();
};
