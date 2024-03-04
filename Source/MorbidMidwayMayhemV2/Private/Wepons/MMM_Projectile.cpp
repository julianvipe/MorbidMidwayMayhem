// Fill out your copyright notice in the Description page of Project Settings.


#include "Wepons/MMM_Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

// Sets default values
AMMM_Projectile::AMMM_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	ProjectileCollision->OnComponentHit.AddDynamic(this, &AMMM_Projectile::OnHit);
	RootComponent = ProjectileCollision;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(ProjectileCollision);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 3000;
	ProjectileMovementComponent->MaxSpeed = 3000;
}

// Called when the game starts or when spawned
void AMMM_Projectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AMMM_Projectile::OnTimer, 1.0f, true);
}

// Called every frame
void AMMM_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMMM_Projectile::OnTimer()
{
		// Increment the counter and debug
		++TimerCount;

		TArray<AActor*> ignoredActors;
		ignoredActors.Add(this);

		// Are we done counting?
		if (TimerCount >= 3)
		{
			bool mu =UGameplayStatics::ApplyRadialDamage(GetWorld(),Damage, GetActorLocation(),Radius, UDamageType::StaticClass(), ignoredActors , this, nullptr, true, ECollisionChannel::ECC_Visibility);
			//DrawDebugSphere(GetWorld(), GetActorLocation(), 500,10,FColor::Blue,false,5.0f);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplotionEffect, GetActorLocation());
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, (mu ? TEXT("true") : TEXT("false")));
			// Clear the timer handle so it won't keep triggering events
			GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
			Destroy();			
		}	
}

void AMMM_Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) )
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, OtherActor->GetActorLabel());
		UGameplayStatics::ApplyDamage(OtherActor, 5, nullptr, this, UDamageType::StaticClass());
	}
}


	



