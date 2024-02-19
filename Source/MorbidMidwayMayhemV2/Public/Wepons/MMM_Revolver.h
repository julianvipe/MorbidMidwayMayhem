// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/MMM_Weapon.h"
#include "MMM_Revolver.generated.h"

/**
 * 
 */
UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_Revolver : public AMMM_Weapon
{
	GENERATED_BODY()

public:
	AMMM_Revolver();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LineTrace");
	float TraceLength;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LineTrace|Debug")
	bool bDrawLineTrace;

protected:

	virtual void StartAction() override;

	virtual void StopAction() override;
	
};
