// Fill out your copyright notice in the Description page of Project Settings.


#include "MMM_Door.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMMM_Door::AMMM_Door()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent = CustomRootComponent;

	DoorFrameComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrameComponent->SetupAttachment(CustomRootComponent);

	DoorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorComponent->SetupAttachment(CustomRootComponent);

	OpenAngle = -90.0f;
}

// Called when the game starts or when spawned
void AMMM_Door::BeginPlay()
{
	Super::BeginPlay();
	OpenDoor();
}

// Called every frame
void AMMM_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMMM_Door::OpenDoor()
{
	FRotator NewRotation = FRotator(0.0f, OpenAngle, 0.0f);
	DoorComponent->SetRelativeRotation(NewRotation);
}
