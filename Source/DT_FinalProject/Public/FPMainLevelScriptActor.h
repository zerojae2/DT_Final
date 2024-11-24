// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "FPMainLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class DT_FINALPROJECT_API AFPMainLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> MainWidget;
protected:
	virtual void BeginPlay() override;
};
