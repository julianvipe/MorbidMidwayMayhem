// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MMM_DoorKey.h"
#include "Components/MeshComponent.h"
#include "MMM_Character.h"

AMMM_DoorKey::AMMM_DoorKey()
{
	KeyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMeshComponent"));
	KeyMeshComponent->SetupAttachment(RootComponent);
	KeyMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	KeyTag = "KeyA";
}

void AMMM_DoorKey::Pickup(AMMM_Character* PickupCharacter)
{
	Super::Pickup(PickupCharacter);

	PickupCharacter->AddKeys(KeyTag);
	Destroy();
}