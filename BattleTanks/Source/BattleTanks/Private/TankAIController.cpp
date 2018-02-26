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


