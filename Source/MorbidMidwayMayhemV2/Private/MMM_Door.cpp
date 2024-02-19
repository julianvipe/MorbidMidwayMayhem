// Fill out your copyright notice in the Description page of Project Settings.


#include "MMM_Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MMM_Character.h"

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

	KeyZone = CreateDefaultSubobject<UBoxComponent>(TEXT("KeyZone"));
	KeyZone->SetupAttachment(CustomRootComponent);
	KeyZone->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	KeyZone->SetCollisionResponseToAllChannels(ECR_Ignore);
	KeyZone->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);

	OpenAngle = -90.0f;
	DoorTag = "KeyA";
	bIsOpen = false;
}

// Called when the game starts or when spawned
void AMMM_Door::BeginPlay()
{
	Super::BeginPlay();
	KeyZone->OnComponentBeginOverlap.AddDynamic(this, &AMMM_Door::CheckKeyFromPlayer);
}

void AMMM_Door::CheckKeyFromPlayer( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bIsOpen)return;

	if (IsValid(OtherActor)) {
		AMMM_Character* OverlappedCharacter = Cast<AMMM_Character>(OtherActor);
		if (IsValid(OverlappedCharacter)) {
			if (OverlappedCharacter->hasKey(DoorTag)) {
				OpenDoor();
			}
		}
	}
}

// Called every frame
void AMMM_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMMM_Door::OpenDoor()
{
	//FRotator NewRotation = FRotator(0.0f, OpenAngle, 0.0f);
	//DoorComponent->SetRelativeRotation(NewRotation);
	BP_OpenDoor();
	bIsOpen = true;

}
