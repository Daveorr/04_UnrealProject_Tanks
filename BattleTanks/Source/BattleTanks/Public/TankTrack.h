// Copyright Von Random 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	// Set a Track Throttle
	UFUNCTION(BlueprintCallable, Category = InGame)
	void SetThrottle ();
};
