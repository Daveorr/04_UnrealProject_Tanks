// Copyright Von Random 2018

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	FVector ForceApplied;
	FVector ForceNormal;
	FVector ForceAxis;
		if (Name == "Left_Track")
		{
			ForceApplied = GetForwardVector() * TrackMaxDrivingForce * Throttle;
			ForceNormal = GetRightVector() * TrackMaxDrivingForce * Throttle ;
			//UE_LOG(LogTemp, Warning, TEXT("%s Throttle ON!"), *Name)
			ForceAxis = GetUpVector() * TrackMaxDrivingForce * Throttle * 100;
		}
		else
		{
			ForceApplied = GetForwardVector() * TrackMaxDrivingForce * Throttle;
			ForceNormal = -GetRightVector() * TrackMaxDrivingForce * Throttle ;
			//UE_LOG(LogTemp, Warning, TEXT("%s Throttle ON!"), *Name)
			ForceAxis = -GetUpVector() * TrackMaxDrivingForce * Throttle * 100;
		}
	// Clamp throttle value so player can't over-drive
	auto ForceResultant = ForceApplied + ForceNormal;
	auto ForceAtLocation = GetComponentLocation();
	// Find the Tank root component
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceResultant, ForceAtLocation);
	TankRoot->AddTorque(ForceAxis);
}



