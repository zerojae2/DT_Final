// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultMonsterAI.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Engine/DamageEvents.h"

ADefaultMonsterAI::ADefaultMonsterAI()
{
	PrimaryActorTick.bCanEverTick = true;
};

void ADefaultMonsterAI::Tick(float DeltaSeconds)
{
	if (APlayerController* asPlayer = GetWorld()->GetFirstPlayerController())
	{
		if (APawn* target = asPlayer->GetPawn())
		{
			MoveToActor(target);

			if (GetPawn()->GetDistanceTo(target) < AttackRange) 
			{
				target->TakeDamage(AttackDamage * DeltaSeconds, FDamageEvent(), this, GetPawn());
			}
			/*
			if (UPawnMovementComponent* movement = GetPawn()->GetMovementComponent()) 
			{
				FVector direction = target->GetActorLocation() - GetPawn()->GetActorLocation();
				direction.Normalize();

				movement->AddInputVector(direction);
			}
			*/
		}
	}
};