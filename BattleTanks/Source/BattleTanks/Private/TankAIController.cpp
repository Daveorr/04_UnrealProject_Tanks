// Copyright Von Random 2018

#include "TankAIController.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay(); // call BeginPlay() method inherited from Actor class
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	if (!AIGetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Assigned to AI"))
	}
	else
	{
		FVector HitLocation; // Out parameter
		if (DetectPlayerTank())
		{
			// Find The Human Player Tank and Aim at its position
			HitLocation = DetectPlayerTank()->GetActorLocation();
			// Aim at Human Player
			AIGetControlledTank()->AimAt(HitLocation);
			// Fire at Human Player
			AIGetControlledTank()->Fire();
			// Move towards Player tank, write in FVector& MoveVelocity
			MoveToActor(DetectPlayerTank(), AcceptanceRadius);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed To Detect The Player"))
		}
	}
}

ATank* ATankAIController::AIGetControlledTank() const
{
	return Cast<ATank>(GetPawn()); // cast to type pawn 
}

ATank* ATankAIController::DetectPlayerTank() const 
{
	APlayerController* PlayerTank;
	PlayerTank = GetWorld()->GetFirstPlayerController();
	return Cast<ATank>(PlayerTank->GetPawn());
}


