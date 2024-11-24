// Fill out your copyright notice in the Description page of Project Settings.


#include "FPDefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AFPDefaultCharacter::AFPDefaultCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void AFPDefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPDefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPDefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AFPDefaultCharacter::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent
	const& DamageEvent,
	class AController*
	EventInstigator,
	AActor* DamageCauser
) 
{
	if (IsValid(EventInstigator) && EventInstigator == GetController()) 
	{
		return 0;
	}

	LaunchCharacter(FVector::UpVector * 100.0f, false, true);
	PlayAnimMontage(DamageMontage);
	healthCurrent -= DamageAmount;

	if (healthCurrent <= 0) 
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), DeathEffect, GetActorLocation(), GetActorRotation(), GetActorScale());
		Destroy();
	}

	return DamageAmount;
}

