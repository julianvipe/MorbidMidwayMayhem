// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MMM_Door.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_Door : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* CustomRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorFrameComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* KeyZone;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My door")
	float OpenAngle;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "My door")
	float bIsOpen;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "My door")
	FName DoorTag;

public:
	// Sets default values for this actor's properties
	AMMM_Door();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void CheckKeyFromPlayer( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OpenDoor();

protected:
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="My door")
	void BP_OpenDoor();
};
