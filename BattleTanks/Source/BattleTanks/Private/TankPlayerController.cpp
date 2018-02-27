// Copyright Von Random 2018

#include "TankPlayerController.h"
#include "BattleTanks.h"

ATank * ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn()); // cast to type pawn 
}
void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();  // call BeginPlay() method inherited from Actor class
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank NOT assigned to the player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank assigned to the player: %s"), *ControlledTank->GetName())
	}
}

void ATankPlayerController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime); 
	// Aim Toward Crossair(); 
	AimTowardsCrosshair();
}



void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Assigned to player"))
	}
	else
	{
		FVector HitLocation; // Out parameter
		// Get the World Location of the Crosshair LineTrace
		GetSightRayHitLocation(HitLocation);
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) 
{
	return DeProjectionOfTheCrossHair(HitLocation);
}

bool ATankPlayerController::DeProjectionOfTheCrossHair(FVector & HitLocation) {
	// Find Crosshair position with de-projection of screen coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewPortSizeX, CrossHairYLocation*ViewPortSizeY);
	FVector WorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection))
	{
		LineTraceCrossHair(WorldDirection, HitLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Deprojection Error"))
	}
	return true;
}

void ATankPlayerController::LineTraceCrossHair(FVector &WorldDirection, FVector & HitLocation) {
	// Parameters for the collision function
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	FCollisionQueryParams TraceParameters(
		FName(TEXT("")),
		false, //only simple collisions
		GetOwner());
	// Line Trace definition (By Channel)
	FVector LineTraceEnd = StartLocation + AIM_DISTANCE * WorldDirection;
	GetWorld()->LineTraceSingleByChannel(
		Hit,
		StartLocation, // ray-casting initial point
		LineTraceEnd, // ray-casting end point
		ECollisionChannel::ECC_Visibility,
		TraceParameters
	);
	HitLocation = Hit.Location;
}
	

 
