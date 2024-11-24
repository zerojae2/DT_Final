// Fill out your copyright notice in the Description page of Project Settings.


#include "FPAnim.h"
#include "GameFramework/PawnMovementComponent.h"

void UFPAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	if (APawn* owner = TryGetPawnOwner()) 
	{
		if (UPawnMovementComponent* movement = owner->GetMovementComponent())
		{
			speed = movement->Velocity.Size2D();
			isJump = movement->IsFalling();
		}
	}
};