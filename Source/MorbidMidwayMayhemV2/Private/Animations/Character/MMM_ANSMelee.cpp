// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/Character/MMM_ANSMelee.h"
#include "MMM_Character.h"

void UMMM_ANSMelee::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	AActor* CharacterActor=MeshComp->GetOwner();
	if (IsValid(CharacterActor)) {
		AMMM_Character* Character = Cast<AMMM_Character>(CharacterActor);
		if (IsValid(Character)) {
			Character->SetMeleeDetectorCollision(ECollisionEnabled::QueryOnly);
		}
	}
}

void UMMM_ANSMelee::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* CharacterActor = MeshComp->GetOwner();
	if (IsValid(CharacterActor)) {
		AMMM_Character* Character = Cast<AMMM_Character>(CharacterActor);
		if (IsValid(Character)) {
			Character->SetMeleeDetectorCollision(ECollisionEnabled::NoCollision);
		}
	}
}
