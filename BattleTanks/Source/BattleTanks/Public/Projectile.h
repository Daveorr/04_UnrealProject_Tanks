// Copyright Von Random 2018

#include "GameFramework/ProjectileMovementComponent.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Launch Projectile
	void LaunchProjectile(float Speed);

private:
	// Projectile Movement Component
	UProjectileMovementComponent * ProjectileMovementComponent = nullptr;
	
	
};
