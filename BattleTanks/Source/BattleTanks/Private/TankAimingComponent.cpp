// Copyright Von Random 2018

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Called when the game starts
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay() 
{
	// So that first first is after initial reload
	LastFiringEvent = FPlatformTime::Seconds();
}


void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet) 
{
	if (ensure(!BarrelToSet || !TurretToSet)) { return; }
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

bool UTankAimingComponent::IsBarrelMoving() 
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01); // vectors are equal
}

void UTankAimingComponent::AimAt(FVector WorldLocation)
{
	if (ensure(!Barrel)) { return; } // Protect Barrel Pointer
	
	FVector OutLaunchVelocity;
	FVector	StartLocation = Barrel->GetSocketLocation(FName("BarrelHole"));

	// Calculate projectile Velocity
	bool VelocityCalculationResult = UGameplayStatics::SuggestProjectileVelocity
	(
		this, //reference to the actual aiming component
		OutLaunchVelocity, // Toss Velocity direction
		StartLocation,	// Start Location
		WorldLocation,	// End Location 
		LaunchSpeed,	// Toss velocity ABS value
		false,	// Select High Arc (artillery mode)
		0,	// Uncertainty on the aiming final location
		false,	// Gravity NOT overriden
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	// Succesfully calculate OutLaunchVelocity
	if (VelocityCalculationResult) 
	{
		// Calculate Out Velocity and print
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // velocity unity vector
		BarrelAimingTowards(AimDirection);
		TurretAimingTowards(AimDirection);
	}
	else
	{
		// UNCOMMENT FOR DEBUG
		//UE_LOG(LogTemp, Warning, TEXT("Unable to Fire at Location"))
	}
}

void UTankAimingComponent::BarrelAimingTowards(FVector AimDirection)
{
	if (ensure(!Barrel)) { return; }

	FRotator AimOrientation = AimDirection.Rotation();	// Get the Aiming orientation
	FRotator BarrelOrientation = Barrel->GetForwardVector().Rotation(); // Get the actual Barrel Orientation
	FRotator DeltaBarrelOrientation = AimOrientation - BarrelOrientation;	// Barrel Required Displacement (deg)

	// Elevate the Barrel
	Barrel->Elevate(DeltaBarrelOrientation.Pitch);
}

void UTankAimingComponent::TurretAimingTowards(FVector AimDirection) 
{
	if (ensure(!Turret)) { return; }
	FRotator AimOrientation = AimDirection.Rotation();	// Get the Aiming orientation
	FRotator TurretOrientation = Turret->GetForwardVector().Rotation(); // Get the actual Turret Orientation
	FRotator DeltaTurretOrientation = AimOrientation - TurretOrientation;	// Turret Required Displacement (deg)
	// Shortest rotation selected
	if (FMath::Abs(DeltaTurretOrientation.Yaw) > 180.F)
	{
		DeltaTurretOrientation.Yaw *= -1.F;
	}
	float Time = GetWorld()->GetTimeSeconds();
	// Rotate the Turret
	Turret->Rotate(DeltaTurretOrientation.Yaw);
}

void UTankAimingComponent::Fire() 
{
	
	float FireEvent = GetWorld()->GetRealTimeSeconds();
	if (FireEvent < CoolDownTime)
	{
		// UNCOMMENT FOR DEBUG
		//UE_LOG(LogTemp, Warning, TEXT("Reloading"))
	}
	else
	{
		LastFiringEvent = GetWorld()->GetRealTimeSeconds();
		CoolDownTime = LastFiringEvent + ReloadTime;
		//UE_LOG(LogTemp, Warning, TEXT("Fired! at time: %f, Cooldown end at: %f"), LastFiringEvent, CoolDownTime)
		// Spawn a Projectile in the given socket location (Barrel Hole)
		auto FiredProjectile = GetWorld()->SpawnActor<AProjectile>
			(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("BarrelHole")),
			Barrel->GetSocketRotation(FName("BarrelHole"))
			);
		FiredProjectile->LaunchProjectile(LaunchSpeed);
	
	}
}

