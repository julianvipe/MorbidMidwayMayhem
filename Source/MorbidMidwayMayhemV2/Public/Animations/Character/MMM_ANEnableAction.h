// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MMM_ANEnableAction.generated.h"

/**
 * 
 */
UCLASS()
class MORBIDMIDWAYMAYHEMV2_API UMMM_ANEnableAction : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
