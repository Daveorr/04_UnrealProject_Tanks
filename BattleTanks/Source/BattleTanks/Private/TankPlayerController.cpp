// Fill out your copyright notice in the Description page of Project Settings.

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

ATank * ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn()); // cast to type pawn 
}
