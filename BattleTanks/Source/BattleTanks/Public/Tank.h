// Copyright Von Random 2018

#include "Engine/World.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "Tank.generated.h"

class AProjectile;	// Forward Declaration of Projectile class

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:	
	
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	// Init value for reload routine
	float LastFiringEvent = 3;	
	float CoolDownTime = 0;
};
