// Copyright Von Random 2018

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * (GetWorld()->DeltaTimeSeconds);
	auto UnClampedNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedNewElevation = FMath::Clamp<float>(UnClampedNewElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(ClampedNewElevation, 0, 0));
}


