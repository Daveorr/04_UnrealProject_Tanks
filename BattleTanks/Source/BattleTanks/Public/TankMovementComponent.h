// Copyright Von Random 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendMoveForward(float Throw);
	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendMoveBackward(float Throw);
	
};
