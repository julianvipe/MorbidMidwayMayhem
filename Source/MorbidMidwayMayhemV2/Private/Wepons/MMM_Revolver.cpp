// Fill out your copyright notice in the Description page of Project Settings.


#include "Wepons/MMM_Revolver.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "MorbidMidwayMayhemV2/MorbidMidwayMayhemV2.h"

AMMM_Revolver::AMMM_Revolver() {

	TraceLength = 10000;
	MuzzleSocketName = "SCK_Muzzle";
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

		FVector TraceEndPoint = TraceEnd;

		FHitResult HitResult;
		bool bHit=GetWorld()->LineTraceSingleByChannel(HitResult, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams);

		if (bHit) {
			//Make Damage

			AActor* HitActor = HitResult.GetActor();
			if (IsValid(HitActor)) {
				UGameplayStatics::ApplyPointDamage(HitActor, Damage, ShotDirection, HitResult, CurrentOwner->GetInstigatorController(), this, DamageType);
			}
			TraceEndPoint = HitResult.ImpactPoint;
			if (IsValid(ImpactEffect)) {
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, TraceEndPoint, HitResult.Normal.Rotation());
			}
		}
		if (bDrawLineTrace) {
			DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::Emerald, false, 1.0f, 0.0f, 1.0f);
		}
		if(IsValid(MuzzleEffect)) {
			UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, CurrentOwnerCharacter->GetMesh(),MuzzleSocketName);
		}
		if (IsValid(TraceEffect)) {

			USkeletalMeshComponent* CharacterMeshComponent = CurrentOwnerCharacter->GetMesh();
			if (IsValid(CharacterMeshComponent)) {
				FVector MuzzleLocation = CharacterMeshComponent->GetSocketLocation(MuzzleSocketName);
				UParticleSystemComponent* TracerComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TraceEffect, MuzzleLocation);
				
				if (IsValid(TracerComponent)) {
					TracerComponent->SetVectorParameter(TraceParamName, TraceEndPoint);
				}
			}
		}
	}
}

void AMMM_Revolver::StopAction() {

	Super::StopAction();
}
