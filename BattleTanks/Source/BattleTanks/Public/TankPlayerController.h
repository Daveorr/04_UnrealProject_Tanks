// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"  // include the Tank C++ header (Pawn Type)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank * GetControlledTank() const; // Player Pawn getter method
	virtual void BeginPlay() override;

};
