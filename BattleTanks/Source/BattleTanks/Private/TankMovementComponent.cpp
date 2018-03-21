// Copyright Von Random 2018

#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to move Forward throw: %f"), Throw)
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendRotateLeft(float Throw) 
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to Rotate Left throw: %f"), Throw)
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendRotateRight(float Throw) 
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to Rotate Right throw: %f"), Throw)
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to Move Backward throw: %f"), Throw)
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO: Prevent Double Speed
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) 
{
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIRequiredDirection = MoveVelocity.GetSafeNormal();
	float AIForwardRequest = FVector::DotProduct(TankForwardDirection, AIRequiredDirection);
	float AIRotationRequest = FVector::CrossProduct(TankForwardDirection, AIRequiredDirection).Z;
	// AI Forward motion actuation
	IntendMoveForward(AIForwardRequest);
	// AI Angular motion actuation with deadzone
	if (abs(AIRotationRequest) > 0.2)
	{
		IntendRotateRight(AIRotationRequest);
	}
	
}