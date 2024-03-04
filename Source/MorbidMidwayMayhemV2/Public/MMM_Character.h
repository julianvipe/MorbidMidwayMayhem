// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MMM_Character.generated.h"

class USkelletalMeshComponent;
class UCameraComponent;
class USpringArmComponent;
class AMMM_Weapon;
class AnimMontage;
class AnimInstance;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* MeleeDetectorComponent;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	bool bUseFPSView;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	bool bIsLookInverted;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Aiming");
	FName FPSCameraSocketName;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Melee");
	FName MeleeSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee")
	float MeleeDamage;

	UPROPERTY(BlueprintReadOnly, Category = "Melee")
	bool bIsDoingMelee;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Key");
	TArray<FName>DoorKeys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon");
	TSubclassOf<AMMM_Weapon> InitialWeaponClass;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon");
	AMMM_Weapon* CurrentWeapon;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bCanUseWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* MeleeMontage;


	UAnimInstance* MyAnimInstance;
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

	void StartMelee();

	void StopMelee();

	UFUNCTION()
	void MakeMeleeDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AddControllerPitchInput(float val) override;

	void AddKeys(FName NewKey);

	bool hasKey(FName KeyTag);

	void SetMeleeDetectorCollision(ECollisionEnabled::Type NewCollisionState);

	void SetActionState(bool NewState);

};
