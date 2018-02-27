// Copyright Von Random 2018

#include "Tank.h"  // include the Tank C++ header (Pawn Type)
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// Player Pawn getter method
	ATank * GetControlledTank() const;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;
	
	float AIM_DISTANCE = 100000.f; // Track crosshair(in cm)
	// Init Aim through crosshair routine
	void AimTowardsCrosshair();
	// Get the hit location
	bool GetSightRayHitLocation();
};
