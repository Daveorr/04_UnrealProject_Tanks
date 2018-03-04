// Copyright Von Random 2018

#include "TankAimingComponent.h"
#include "Engine/World.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Tank Aiming Routine 
	void AimAt(FVector Hitlocation);
	
	// Barrel movement Routine (callable from Blueprint)
	UFUNCTION(BlueprintCallable, Category = Setup)	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Turret movement Routine (callable from Blueprint)
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	// Tank Fire a Projectile
	UFUNCTION(BlueprintCallable, Category = InGame)
	void Fire();

protected:

	UTankAimingComponent * TankAimingComponent = nullptr;

private:	
	
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Projectile Velocity
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 140000;	// Typical Projectile Fly speed
	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTime = 3;	// in seconds

	float LastFiringEvent = 3;	// in seconds
	float CoolDownTime = 0;
};
