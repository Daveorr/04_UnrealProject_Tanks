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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	ATank* AIGetControlledTank() const; // AI Pawn getter method
	ATank* DetectPlayerTank() const;
};
