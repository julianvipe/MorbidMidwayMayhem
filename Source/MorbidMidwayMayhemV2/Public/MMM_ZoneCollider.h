// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MMM_ZoneCollider.generated.h"

class UBoxComponent;

UCLASS()
class MORBIDMIDWAYMAYHEMV2_API AMMM_ZoneCollider : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* MainColliderComponent;
	
public:	
	// Sets default values for this actor's properties
	AMMM_ZoneCollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Action(AMMM_Character* CharacterInZone);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Zone")
	void BP_Action(AMMM_Character* CharacterInZone);

	virtual void OutOfAction(AMMM_Character* CharacterInZone);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Zone")
	void BP_OutOfAction(AMMM_Character* CharacterInZone);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor)override;
};
