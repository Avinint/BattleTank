// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName(TEXT("Aiming_component")));
}

void ATank::SetBarrelReference(UTankBarrel * Barrel)
{
	TankAimingComponent->SetBarrelReference(Barrel);
}

void ATank::SetTurretReference(UTankTurret * Turret)
{
	TankAimingComponent->SetTurretReference(Turret);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : Tank firing!!"), Time)
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

