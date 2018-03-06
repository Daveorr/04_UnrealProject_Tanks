// Copyright Von Random 2018

#include "TankMovementComponent.h"



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend to move Forward throw: %f"),Throw)
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend to move Backward throw: %f"), Throw)
}
