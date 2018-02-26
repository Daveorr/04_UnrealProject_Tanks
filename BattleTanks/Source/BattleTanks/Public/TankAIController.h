// Copyright Von Random 2018
#include "Tank.h"
#include "Engine/World.h"
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	ATank* AIGetControlledTank() const; // AI Pawn getter method
	ATank* DetectPlayerTank() const;
};
