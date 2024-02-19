// Fill out your copyright notice in the Description page of Project Settings.


#include "MMM_ZoneCollider.h"
#include "Components/BoxComponent.h"
#include "MMM_Character.h"

// Sets default values
AMMM_ZoneCollider::AMMM_ZoneCollider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainColliderComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MainColliderComponent"));
	MainColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MainColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	MainColliderComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMMM_ZoneCollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMMM_ZoneCollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMMM_ZoneCollider::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);
	if (IsValid(otherActor))
	{
		AMMM_Character* OverlappedCharacter = Cast<AMMM_Character>(otherActor);
		if (IsValid(OverlappedCharacter)) {
			Action(OverlappedCharacter);
		}
	}
}

void AMMM_ZoneCollider::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	AMMM_Character* OverlappedCharacter = Cast<AMMM_Character>(OtherActor);
	OutOfAction(OverlappedCharacter);
}

void AMMM_ZoneCollider::Action(AMMM_Character* CharacterInZone)
{
	BP_Action(CharacterInZone);
}

void AMMM_ZoneCollider::OutOfAction(AMMM_Character* CharacterInZone)
{
	BP_OutOfAction(CharacterInZone);
}

