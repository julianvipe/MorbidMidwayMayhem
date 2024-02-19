// Fill out your copyright notice in the Description page of Project Settings.


#include "Wepons/MMM_Revolver.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

AMMM_Revolver::AMMM_Revolver() {

	TraceLength = 10000;
}

void AMMM_Revolver::StartAction() {

	Super::StartAction();

	AActor* CurrentOwner = GetOwner();
	if (IsValid(CurrentOwner)) {
		FVector EyeLocation;
		FRotator EyeRotator;

		CurrentOwner->GetActorEyesViewPoint(EyeLocation, EyeRotator);

		FVector ShotDirection = EyeRotator.Vector();
		FVector TraceEnd = EyeLocation + (ShotDirection * TraceLength);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		QueryParams.AddIgnoredActor(CurrentOwner);
		QueryParams.bTraceComplex = true;

		FHitResult HitResult;
		bool bHit=GetWorld()->LineTraceSingleByChannel(HitResult, EyeLocation, TraceEnd, ECC_Visibility, QueryParams);

		if (bHit) {
			//Make Damage

			AActor* HitActor = HitResult.GetActor();
			if (IsValid(HitActor)) {
				UGameplayStatics::ApplyPointDamage(HitActor, Damage, ShotDirection, HitResult, CurrentOwner->GetInstigatorController(), this, DamageType);
			}
		}
		if (bDrawLineTrace) {
			DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::Emerald, false, 1.0f, 0.0f, 1.0f);
		}


	}
}

void AMMM_Revolver::StopAction() {

	Super::StopAction();
}
