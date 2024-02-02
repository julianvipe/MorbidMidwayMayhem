// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/MMM_Item.h"
#include "MMM_DoorKey.generated.h"

class UStaticMeshcomponent;
/**
 * 
 */
UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_DoorKey : public AMMM_Item
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* KeyMeshComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Key")
	FName KeyTag;

public:
	// Sets default values for this actor's properties
	AMMM_DoorKey();

public:
	UFUNCTION(BlueprintCallable, Category = "Getter")
	FName GetKeyTag() const { return KeyTag; };

protected:
	void Pickup(AMMM_Character* PickupCharacter);
};
