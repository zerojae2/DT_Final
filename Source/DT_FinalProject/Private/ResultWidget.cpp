// Fill out your copyright notice in the Description page of Project Settings.


#include "ResultWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "FPDefaultGameState.h"
#include "Kismet/GameplayStatics.h"

void UResultWidget::NativeConstruct()
{
	if (AFPDefaultGameState* myState = CastChecked<AFPDefaultGameState>(UGameplayStatics::GetGameState(GetWorld())))
	{
		ScoreTextBlock = CastChecked<UTextBlock>(GetWidgetFromName(TEXT("ScoreText")));

		if (IsValid(ScoreTextBlock))
		{
			ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("Score : %d"), FMath::FloorToInt(myState->GetScore()))));
		};
	};

	MainMenuButton = CastChecked<UButton>(GetWidgetFromName(TEXT("MainMenuButton")));

	if (IsValid(MainMenuButton)) 
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UResultWidget::OnMainMenuClicked);
	} 
};
void UResultWidget::OnMainMenuClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
};
