// Copyright Von Random 2018

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) 
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto OrientationChange = RelativeSpeed * MaxDegreePerSecond * (GetWorld()->DeltaTimeSeconds);
	auto NewRotation = RelativeRotation.Yaw + OrientationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
	UE_LOG(LogTemp, Warning, TEXT("I'm ROtating: %s"), *FRotator(0, NewRotation,0).ToString())
}





