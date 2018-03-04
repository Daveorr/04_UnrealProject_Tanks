// Copyright Von Random 2018

#include "Tank.h"



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
}

void ATank::SetTurretReference(UTankTurret * TurretToSet) 
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	float FireEvent = GetWorld()->GetRealTimeSeconds();
	if (FireEvent < CoolDownTime)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reloading"))
	}
	else
	{
		LastFiringEvent = GetWorld()->GetRealTimeSeconds();
		CoolDownTime = LastFiringEvent + ReloadTime;
		UE_LOG(LogTemp, Warning, TEXT("Fired! at time: %f, Cooldown end at: %f"), LastFiringEvent, CoolDownTime)
	}
}


