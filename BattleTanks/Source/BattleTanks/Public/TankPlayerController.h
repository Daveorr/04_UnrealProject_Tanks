// Copyright Von Random 2018

#include "Tank.h"  // include the Tank C++ header (Pawn Type)

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

public:
	// Player Pawn getter method
	ATank * GetControlledTank() const;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	// Init Aim through crosshair routine
	void AimTowardsCrosshair();
};
