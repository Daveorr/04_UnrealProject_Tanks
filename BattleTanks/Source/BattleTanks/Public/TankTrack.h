// Copyright Von Random 2018

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	// Axial Force exerted by the track (Newton)
	UPROPERTY(EditDefaultsOnly, Category = Moving)
	float TrackMaxDrivingForce = 40000000;	

	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);


private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ComputeSidewayForce();

	float CurrentThrottle = 0;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

};
