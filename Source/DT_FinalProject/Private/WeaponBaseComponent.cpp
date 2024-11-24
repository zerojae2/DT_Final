// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBaseComponent.h"

// Sets default values for this component's properties
UWeaponBaseComponent::UWeaponBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UWeaponBaseComponent::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Attacked"));
}

// Called when the game starts
void UWeaponBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	float currentTime = GetOwner()->GetGameTimeSinceCreation();

	if (currentTime >= LastShotTime + Cooldown) 
	{
		Attack();

		LastShotTime = currentTime;
	}
}

