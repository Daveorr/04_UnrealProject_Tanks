// Copyright Von Random 2018
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"




// Sets default values (Tank Class Constructor)
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();	// needed for BP begin Play to run
}



