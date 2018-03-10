// Copyright Von Random 2018
#include "GameFramework/PlayerController.h"
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

public:
	// Called Every Frame
	virtual void Tick(float DeltaSeconds) override;
	

protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 8000;
	virtual void SetPawn(APawn* InPawn) override;
private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
