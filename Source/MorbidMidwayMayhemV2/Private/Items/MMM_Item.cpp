// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MMM_Item.h"
#include "Components/SphereComponent.h"
#include "MMM_Character.h"

// Sets default values
AMMM_Item::AMMM_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MainColliderComponent"));
	MainColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MainColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = MainColliderComponent;

}

// Called when the game starts or when spawned
void AMMM_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMMM_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMMM_Item::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);
	if (IsValid(otherActor))
	{
		AMMM_Character* OverlappedCharacter = Cast<AMMM_Character>(otherActor);
		if (IsValid(OverlappedCharacter)) {
			Pickup(OverlappedCharacter);
		}
	}
}

void AMMM_Item::Pickup(AMMM_Character* PickupCharacter)
{
	BP_Pickup(PickupCharacter);
}



