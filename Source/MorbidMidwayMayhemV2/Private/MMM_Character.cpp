// Fill out your copyright notice in the Description page of Project Settings.


#include "MMM_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapon/MMM_Weapon.h"

// Sets default values
AMMM_Character::AMMM_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseFPSView = true;
	FPSCameraSocketName = "SCK_Camera";

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS_CameraComponent"));
	FPSCameraComponent->bUsePawnControlRotation = true;
	FPSCameraComponent->SetupAttachment(GetMesh(), FPSCameraSocketName);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);

	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TPS_CameraComponent"));
	TPSCameraComponent->SetupAttachment(SpringArmComponent);


}

FVector AMMM_Character::GetPawnViewLocation() const
{
	if (IsValid(FPSCameraComponent) && bUseFPSView) {
		return FPSCameraComponent->GetComponentLocation();
	}
	else if(IsValid(TPSCameraComponent) && !bUseFPSView) {
		return TPSCameraComponent->GetComponentLocation();
	}
	else {
		return Super::GetPawnViewLocation();
	}
}

// Called when the game starts or when spawned
void AMMM_Character::BeginPlay()
{
	Super::BeginPlay();

	CreateInitialWeapon();

}

// Called every frame
void AMMM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMMM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveFoward", this, &AMMM_Character::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMMM_Character::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMMM_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMMM_Character::Jump);
	PlayerInputComponent->BindAction("StopJumping", IE_Released, this, &AMMM_Character::StopJumping);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMMM_Character::Crouch);
	PlayerInputComponent->BindAction("UnCrouch", IE_Released, this, &AMMM_Character::UnCrouch);

	PlayerInputComponent->BindAction("WeaponAction", IE_Pressed, this, &AMMM_Character::StartWeaponAction);
	PlayerInputComponent->BindAction("WeaponAction", IE_Released, this, &AMMM_Character::StopWeaponAction);

}


void AMMM_Character::MoveFoward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AMMM_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AMMM_Character::AddControllerPitchInput(float val)
{
	Super::AddControllerPitchInput(bIsLookInverted ? -val : val);
}


void AMMM_Character::Jump()
{
	Super::Jump();
}

void AMMM_Character::StopJumping()
{
	Super::StopJumping();
}

void AMMM_Character::Crouch()
{
	Super::Crouch();
}

void AMMM_Character::UnCrouch()
{
	Super::UnCrouch();
}

void AMMM_Character::CreateInitialWeapon()
{
	if (IsValid(InitialWeaponClass)) {
		CurrentWeapon = GetWorld()->SpawnActor<AMMM_Weapon>(InitialWeaponClass, GetActorLocation(), GetActorRotation());

		if (IsValid(CurrentWeapon))
		{
			CurrentWeapon->SetOwner(this);
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		}
	}
}

void AMMM_Character::StartWeaponAction()
{
	if (IsValid(CurrentWeapon)) {
		CurrentWeapon->StartAction();
	}
}

void AMMM_Character::StopWeaponAction()
{
	if (IsValid(CurrentWeapon)) {
		CurrentWeapon->StopAction();
	}

}

void AMMM_Character::AddKeys(FName NewKey)
{
	DoorKeys.Add(NewKey);
}

bool AMMM_Character::hasKey(FName KeyTag)
{
	return DoorKeys.Contains(KeyTag);
}

