// Copyright Von Random 2018

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"



// Sets default values (Tank Class Constructor)
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector Hitlocation)
{
	TankAimingComponent->AimAt(Hitlocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet) 
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;	// keep a local reference
}

void ATank::SetTurretReference(UTankTurret * TurretToSet) 
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel || !ProjectileBluePrint) { UE_LOG(LogTemp, Warning, TEXT("ERROR! CHECK BARREL AND PROJECTILE_BP")) return; }	//Pointer protection
	float FireEvent = GetWorld()->GetRealTimeSeconds();
	if (FireEvent < CoolDownTime)
	{
		// UNCOMMENT FOR DEBUG
		//UE_LOG(LogTemp, Warning, TEXT("Reloading"))
	}
	else
	{
		LastFiringEvent = GetWorld()->GetRealTimeSeconds();
		CoolDownTime = LastFiringEvent + ReloadTime;
		//UE_LOG(LogTemp, Warning, TEXT("Fired! at time: %f, Cooldown end at: %f"), LastFiringEvent, CoolDownTime)
		// Spawn a Projectile in the given socket location (Barrel Hole)
		auto FiredProjectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("BarrelHole")),
			Barrel->GetSocketRotation(FName("BarrelHole")));
		FiredProjectile->LaunchProjectile(LaunchSpeed);
	}
}


