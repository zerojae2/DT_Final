// Fill out your copyright notice in the Description page of Project Settings.


#include "FPDefaultGameState.h"
#include "FPGameMainWidget.h"
#include "Kismet/GameplayStatics.h"
#include "DefaultMonsterAI.h"
#include "Engine/DamageEvents.h"


AFPDefaultGameState::AFPDefaultGameState() 
{
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FClassFinder<UFPGameMainWidget> mainWidgetFinder(TEXT("/Game/Widgets/GameMainWidget"));
	if (mainWidgetFinder.Succeeded())
	{
		MainWidget = mainWidgetFinder.Class;
	};

	ConstructorHelpers::FClassFinder<UUserWidget> winWidgetFinder(TEXT("/Game/Widgets/WinWidget"));
	if (winWidgetFinder.Succeeded())
	{
		WinWidget = winWidgetFinder.Class;
	}
	ConstructorHelpers::FClassFinder<UUserWidget> loseWidgetFinder(TEXT("/Game/Widgets/LoseWidget"));
	if (loseWidgetFinder.Succeeded())
	{
		LoseWidget = loseWidgetFinder.Class;
	}
}

void AFPDefaultGameState::BeginPlay() 
{
	LeftTime = ClearTime;
	playerCharacter = CastChecked<AFPDefaultCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (IsValid(MainWidget)) 
	{
		if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainWidget)) 
		{
			created->AddToPlayerScreen(0);

			if (UFPGameMainWidget* asGameMain = CastChecked<UFPGameMainWidget>(created))
			{
				asGameMain->currentState = this;
				asGameMain->currentCharacter = playerCharacter;
			};
		}
	}
}

void AFPDefaultGameState::Tick(float DeltaSeconds) 
{
	if (currentState == Play && LeftTime > 0) 
	{
		LeftTime -= DeltaSeconds;
		Score += DeltaSeconds;

		if (LeftTime <= 0)
		{
			LeftTime = 0;
			WinGame();
		};

		if (IsValid(playerCharacter) == false || playerCharacter->GetHealthRate() <= 0) 
		{
			LoseGame();
		}
	}
}

void AFPDefaultGameState::WinGame()
{
	currentState = Win;
	if (IsValid(WinWidget))
	{
		if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), WinWidget))
		{
			created->AddToPlayerScreen(0);
		};
	};

	TArray<AActor*> actors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADefaultMonsterAI::StaticClass(), actors);

	if (actors.Num() > 0)
	{
		for (AActor* currentActor : actors)
		{
			if (ADefaultMonsterAI* asMonsterAI = CastChecked<ADefaultMonsterAI>(currentActor))
			{
				if (APawn* asPawn = asMonsterAI->GetPawn()) 
				{
					asPawn->TakeDamage(FLT_MAX, FDamageEvent(), nullptr, nullptr);
				}
			};
		};
	};
}

void AFPDefaultGameState::LoseGame()
{
	currentState = Lose;
	if (IsValid(LoseWidget))
	{
		if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), LoseWidget))
		{
			created->AddToPlayerScreen(0);
		};
	};
}

FString AFPDefaultGameState::GetTimeString() 
{
	int leftTimeAsInt = FMath::FloorToInt(LeftTime);
	return FString::Printf(TEXT("%d : %d"), leftTimeAsInt / 60, leftTimeAsInt % 60);
}
