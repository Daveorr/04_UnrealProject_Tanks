// Copyright Von Random 2018

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// associate to this class a movement component subobject, no need to protect. 
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	// We don't want the projectile to be fired when it is constructed (only if Fire event true)
	ProjectileMovementComponent->bAutoActivate = false;
}
	

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}


void AProjectile::LaunchProjectile(float Speed) 
{
	if (!ProjectileMovementComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR IN FIRING!"))
	}
	// ForwardVector is refered to the barrel orientation, fire at given speed along the barrel direction
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovementComponent->Activate();
}

