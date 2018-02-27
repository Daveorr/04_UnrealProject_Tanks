// Copyright Von Random 2018

#include "TankAIController.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay(); // call BeginPlay() method inherited from Actor class
	auto ControlledTank = AIGetControlledTank();
	auto PlayerTank = DetectPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank NOT assigned to the AI"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank assigned to the AI: %s"), *ControlledTank->GetName())
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player NOT sensed"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tanks sensed player Tank: %s"), *PlayerTank->GetName())
	}
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
			AIGetControlledTank()->AimAt(HitLocation);
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


