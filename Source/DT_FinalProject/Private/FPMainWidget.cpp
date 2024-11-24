// Fill out your copyright notice in the Description page of Project Settings.


#include "FPMainWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UFPMainWidget::NativeConstruct()
{
	GameStartButton = Cast<UButton>(GetWidgetFromName(TEXT("GameStartButton")));
	GameQuitButton = Cast<UButton>(GetWidgetFromName(TEXT("GameQuitButton")));

	if(IsValid(GameStartButton)) GameStartButton->OnClicked.AddDynamic(this, &UFPMainWidget::GameStartClicked);
	if (IsValid(GameQuitButton)) GameQuitButton->OnClicked.AddDynamic(this, &UFPMainWidget::GameQuitClicked);
};
void UFPMainWidget::GameStartClicked() 
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("InGame"));
}
void UFPMainWidget::GameQuitClicked() 
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}