// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MMM_Character.generated.h"

class UCameraComponent;
class USpringArmComponent;
class AMMM_Weapon;

UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_Character : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* TPSCameraComponent;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	bool bUseFPSView;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	bool bIsLookInverted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	FName FPSCameraSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Key");
	TArray<FName>DoorKeys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon");
	TSubclassOf<AMMM_Weapon> InitialWeaponClass;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon");
	AMMM_Weapon* CurrentWeapon;

public:
	// Sets default values for this character's properties
	AMMM_Character();

	virtual FVector GetPawnViewLocation() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveFoward(float value);

	void MoveRight(float value);

	virtual void Jump() override;

	virtual void StopJumping() override;

	void Crouch();

	void UnCrouch();

	void CreateInitialWeapon();

	void StartWeaponAction();

	void StopWeaponAction();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AddControllerPitchInput(float val) override;

	void AddKeys(FName NewKey);

	bool hasKey(FName KeyTag);

};
