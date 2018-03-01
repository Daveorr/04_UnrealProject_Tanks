// Copyright Von Random 2018

#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; // Forward Declaration (Hold Barrel's physical parameters)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Tank Aiming Routine
	void AimAt(FVector WorldLocation, float LaunchSpeed);

	// Set Barrel Position
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Set Barrel Orientation with angular speeds constraints
	void BarrelAimingTowards(FVector AimDirection);

private:
	// Barrel Position
	UTankBarrel * Barrel = nullptr;
};
