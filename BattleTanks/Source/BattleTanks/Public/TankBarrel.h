// Copyright Von Random 2018

#include "Engine/World.h"

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/* Bring the custom class available for blueprint use with following command */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Elevate the barrel with a certain angular velocity
	void Elevate(float RelativeSpeed);
private:
	// Tank Motion Physical Contraint Parameters
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegree = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegree = 0;
};
