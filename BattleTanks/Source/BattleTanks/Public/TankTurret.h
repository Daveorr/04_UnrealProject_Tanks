// Copyright Von Random 2018

#include "Engine/World.h"

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/* Bring the custom class available for blueprint use with following command */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Rotate the Turret with a certain angular velocity
	void Rotate(float RelativeSpeed);

private:
	// Tank Turret Motion Physical Contraint Parameters
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 25;
};
