// Copyright Von Random 2018

#include "TankTrack.h"

void UTankTrack::SetThrottle()
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle ON!"), *Name)
}



