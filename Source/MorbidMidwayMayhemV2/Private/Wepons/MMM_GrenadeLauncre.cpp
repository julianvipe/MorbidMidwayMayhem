// Fill out your copyright notice in the Description page of Project Settings.


#include "Wepons/MMM_GrenadeLauncre.h"
#include "Wepons/MMM_Projectile.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

AMMM_GrenadeLauncher::AMMM_GrenadeLauncher() {
	MuzzleSocketName = "SCK_Muzzle";
}


void AMMM_GrenadeLauncher::StartAction()
{
	Super::StartAction();

	if (IsValid(CurrentOwnerCharacter)) {
		USkeletalMeshComponent* CharacterMeshComponent = CurrentOwnerCharacter->GetMesh();
		if (IsValid(CharacterMeshComponent)) {
			FVector MuzzleLocation = CharacterMeshComponent->GetSocketLocation(MuzzleSocketName);
			FRotator MuzzleRotator = CharacterMeshComponent->GetSocketRotation(MuzzleSocketName);

			AMMM_Projectile* CurrentProjectile = GetWorld()->SpawnActor<AMMM_Projectile>(ProjectileClass, MuzzleLocation, MuzzleRotator);
		}
	}
}

void AMMM_GrenadeLauncher::StopAction()
{

	Super::StopAction();
}