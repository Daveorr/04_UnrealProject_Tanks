// Copyright Von Random 2018

#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};


class UTankBarrel;  // Forward Declaration (Hold Barrel's physical parameters)
class UTankTurret; // Forward Declaration (Hold Turret's physical parameters)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Tank Aiming Routine
	void AimAt(FVector WorldLocation, float LaunchSpeed);

	// Set Barrel Position
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Set Turret Position
	void SetTurretReference(UTankTurret * TurretToSet);

	// Set Barrel Orientation with angular speeds constraints
	void BarrelAimingTowards(FVector AimDirection);

	// Set Turret Orientation with angular speeds constraints
	void TurretAimingTowards(FVector AimDirection);

	//Detect if Barrel is moving
	bool IsBarrelMoving();

	//Return firing state
	EFiringState GetFiringState() const;

private:
	// Barrel Position
	UTankBarrel * Barrel = nullptr;
	// Turret Position
	UTankTurret * Turret = nullptr;
	// Actual Aiming direction
	FVector AimDirection;
};
