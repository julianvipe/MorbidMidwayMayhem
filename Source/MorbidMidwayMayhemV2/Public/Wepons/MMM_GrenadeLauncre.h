// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/MMM_Weapon.h"
#include "MMM_GrenadeLauncre.generated.h"

class AMMM_Projectile;
/**
 * 
 */
UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_GrenadeLauncher : public AMMM_Weapon
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GrenadeLauncher");
	TSubclassOf<AMMM_Projectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects");
	FName MuzzleSocketName;

public:
	AMMM_GrenadeLauncher();

protected:

	virtual void StartAction() override;

	virtual void StopAction() override;

	
};
