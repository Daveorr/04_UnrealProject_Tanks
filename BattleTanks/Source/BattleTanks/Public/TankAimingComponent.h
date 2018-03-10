// Copyright Von Random 2018
#include "Projectile.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;  // Forward Declaration (Hold Barrel's physical parameters)
class UTankTurret; // Forward Declaration (Hold Turret's physical parameters)

// Firing status reporter declaration
UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret * TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	
	// Firing Status init
	UPROPERTY(BlueprintReadOnly, Category = InGame)
	EFiringStatus FiringState = EFiringStatus::Aiming;

private:	

	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	// Set Barrel Orientation with angular speeds constraints
	void BarrelAimingTowards(FVector AimDirection);

	// Set Turret Orientation with angular speeds constraints
	void TurretAimingTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		double CoolDownTime = 3;

	double LastFiringEvent = 0;
	double ReloadTime = LastFiringEvent + CoolDownTime;

	FVector AimDirection;

};
