// Copyright Von Random 2018
#include "TankPlayerController.h"
#include "Tank.h"
#include "BattleTanks.h"

void ATankPlayerController::SetPawn(APawn * InPawn) 
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
	}
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();  // call BeginPlay() method inherited from Actor class
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(!AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime); 
	// Aim Toward Crossair(); 
	AimTowardsCrosshair();
}



void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetPawn()) { return; } // e.g. if not possessing
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent)) { return; }
	
	FVector HitLocation; // Out parameter
	// Get the World Location of the Crosshair LineTrace
	GetSightRayHitLocation(HitLocation);
	AimingComponent->AimAt(HitLocation);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) 
{
	return DeProjectionOfTheCrossHair(HitLocation);
}

bool ATankPlayerController::DeProjectionOfTheCrossHair(FVector & HitLocation) 
{
	// Find Crosshair position with de-projection of screen coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewPortSizeX, CrossHairYLocation*ViewPortSizeY);
	FVector WorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection))
	{
		LineTraceCrossHair(WorldDirection, HitLocation);
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Deprojection Error"))
		return false;
	}
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
	

 
