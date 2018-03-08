// Copyright Von Random 2018
#include "TankTrack.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Responsible from driving the tank track
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	// Constructor
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet);

	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendMoveForward(float Throw);
	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendMoveBackward(float Throw);
	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendRotateLeft(float Throw);
	// move forward
	UFUNCTION(BlueprintCallable, Category = Moving)
		void IntendRotateRight(float Throw);

	/** path following: request new velocity */
		virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
