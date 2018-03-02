// Copyright Von Random 2018

#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector WorldLocation, float LaunchSpeed)
{
	if (!Barrel) { return; } // Protect Barrel Pointer
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
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to Fire at Location"))
	}
}

void UTankAimingComponent::BarrelAimingTowards(FVector AimDirection)
{
	FRotator AimOrientation = AimDirection.ToOrientationRotator();	// Get the Aiming orientation
	FRotator BarrelOrientation = Barrel->GetForwardVector().ToOrientationRotator(); // Get the actual Barrel Orientation
	FRotator DeltaBarrelOrientation = AimOrientation - BarrelOrientation;	// Barrel Required Displacement (deg)
	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Time %f: Aiming at %s with offset: %s"),Time ,*AimOrientation.ToString(), *DeltaBarrelOrientation.ToString())
	// Elevate the Barrel
	Barrel->Elevate(DeltaBarrelOrientation.Pitch);
}



