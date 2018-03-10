// Copyright Von Random 2018

#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TankAimingComponent.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	void SetPawn(APawn * InPawn);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Init Aim through crosshair routine
	void AimTowardsCrosshair();
	// Get the hit location
	bool GetSightRayHitLocation(FVector &HitLocation);
	bool DeProjectionOfTheCrossHair(FVector & HitLocation);
	void LineTraceCrossHair(FVector &WorldDirection, FVector & HitLocation);


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;
	
	float AIM_DISTANCE = 100000.f; // Track crosshair(in cm)
	
};
