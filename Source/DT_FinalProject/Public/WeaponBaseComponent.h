// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponBaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DT_FINALPROJECT_API UWeaponBaseComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown", meta = (AllowPrivateAccess = "true"))
	float Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown", meta = (AllowPrivateAccess = "true"))
	float LastShotTime;
public:	
	// Sets default values for this component's properties
	UWeaponBaseComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void Attack();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
