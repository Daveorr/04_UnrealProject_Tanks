// Copyright Von Random 2018

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	FVector ForceApplied;
	ForceApplied = GetForwardVector() * TrackMaxDrivingForce * Throttle;
	// Clamp throttle value so player can't over-drive
	auto ForceAtLocation = GetComponentLocation();
	// Find the Tank root component
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceAtLocation);
}
