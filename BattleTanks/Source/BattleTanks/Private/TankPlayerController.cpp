// Copyright Von Random 2018

#include "TankPlayerController.h"
#include "BattleTanks.h"

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

ATank * ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn()); // cast to type pawn 
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank())
	{
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Init Aim routine"))
	}
}


