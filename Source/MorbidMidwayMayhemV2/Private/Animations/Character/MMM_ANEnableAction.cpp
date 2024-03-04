// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/Character/MMM_ANEnableAction.h"
#include "MMM_Character.h"

void UMMM_ANEnableAction::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* CharacterActor = MeshComp->GetOwner();
	if (IsValid(CharacterActor)) {
		AMMM_Character* Character = Cast<AMMM_Character>(CharacterActor);
		if (IsValid(Character)) {
			Character->SetActionState(false);
		}
	}
}
