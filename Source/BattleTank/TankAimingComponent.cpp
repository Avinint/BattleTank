// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * Barrel)
{
	this->Barrel = Barrel;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * Turret)
{
	this->Turret = Turret;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		auto Time = GetWorld()->GetTimeSeconds();
		MoveTurret(AimDirection);
		MoveBarrel(AimDirection);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : No solution found"), Time);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsARotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsARotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	auto Rotator = Turret->GetForwardVector().Rotation();
	auto AimAsARotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsARotator - Rotator;
	
	Turret->Rotate(DeltaRotator.Yaw);
}

