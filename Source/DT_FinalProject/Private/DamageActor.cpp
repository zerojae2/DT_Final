// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageActor.h"
#include "Engine/DamageEvents.h"
#include "NiagaraFunctionLibrary.h"

#include "Camera/CameraShakeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADamageActor::NotifyHit
(
	class UPrimitiveComponent* MyComp,
	AActor* Other,
	class UPrimitiveComponent* OtherComp,
	bool bSelfMoved,
	FVector HitLocation,
	FVector HitNormal,
	FVector NormalImpulse,
	const FHitResult& Hit
) 
{
	if (IsValid(Other)) 
	{
		AController* instigator = nullptr;
		if (IsValid(Owner)) 
		{
			instigator = Owner->GetInstigatorController();
		}
		if (Other->TakeDamage(Damage, FDamageEvent(), instigator, this) > 0) 
		{
			if (APlayerController* asPlayer = UGameplayStatics::GetPlayerController(GetWorld(), 0)) 
			{
				asPlayer->ClientStartCameraShake(Shake);
			}
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, GetActorLocation());
			Destroy();
		}
	}
}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

