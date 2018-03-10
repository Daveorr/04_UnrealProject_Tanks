// Copyright Von Random 2018

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay(); // call BeginPlay() method inherited from Actor class
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AIControlledTank = GetPawn();

	if (ensure(!AIControlledTank || !PlayerTank)){ return; }
	FVector HitLocation; // Out parameter
	// Find The Human Player Tank and Aim at its position
	HitLocation = PlayerTank->GetActorLocation();
	// Aim at Human Player
	auto AimingComponent = AIControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(HitLocation);
	// Fire at Human Player TODO LIMIT FIRING RATE
	//AimingComponent->Fire(); // TODO limit firing rate
	// Move towards Player tank, write in FVector& MoveVelocity
	MoveToActor(PlayerTank, AcceptanceRadius);
}

void ATankAIController::SetPawn(APawn* InPawn) 
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
	}
}



