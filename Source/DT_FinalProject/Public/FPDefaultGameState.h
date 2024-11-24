// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPDefaultGameState.generated.h"

enum GameClearState 
{
	Play,
	Lose,
	Win
};

/**
 * 
 */
UCLASS()
class DT_FINALPROJECT_API AFPDefaultGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	class AFPDefaultCharacter* playerCharacter = nullptr;

	GameClearState currentState = GameClearState::Play;

	UPROPERTY(EditAnywhere, Category = "Play", meta = (AllowPrivateAccess = "true"))
	float ClearTime = 60.f;
	float LeftTime;

	float Score;

	TSubclassOf<class UFPGameMainWidget> MainWidget;

	TSubclassOf<class UUserWidget> WinWidget;
	TSubclassOf<class UUserWidget> LoseWidget;

	
public:
	AFPDefaultGameState();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void WinGame();
	virtual void LoseGame();

public:
	virtual FString GetTimeString();

	void AddScore(float wantScore) { Score += wantScore; };
	float GetScore() { return Score; };
};
