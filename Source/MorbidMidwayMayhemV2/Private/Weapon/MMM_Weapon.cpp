// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/MMM_Weapon.h"
#include "GameFramework/DamageType.h"

// Sets default values
AMMM_Weapon::AMMM_Weapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Damage = 20.0f;

}

// Called when the game starts or when spawned
void AMMM_Weapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMMM_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMMM_Weapon::StartAction()
{
	BP_StartAction();
}

void AMMM_Weapon::StopAction()
{
	BP_StopAction();
}
