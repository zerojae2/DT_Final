// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPauseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UFPPauseWidget::OnResumeClicked()
{
	RemoveFromParent();
};

void UFPPauseWidget::OnMainClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
};

void UFPPauseWidget::NativeConstruct() 
{
	ResumeButton = CastChecked<UButton>(GetWidgetFromName(TEXT("ResumeButton")));
	MainButton = CastChecked<UButton>(GetWidgetFromName(TEXT("MainButton")));

	if (IsValid(ResumeButton)) 
	{
		ResumeButton->OnClicked.AddDynamic(this, &UFPPauseWidget::OnResumeClicked);
	}

	if (IsValid(MainButton)) MainButton->OnClicked.AddDynamic(this, &UFPPauseWidget::OnMainClicked);

	PlayAnimation(StartPauseAnimation);
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
void UFPPauseWidget::NativeDestruct() 
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	//시간이 지나는 속도를 정함
	//UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.5f);
}