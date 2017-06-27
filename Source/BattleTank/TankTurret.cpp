// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

// RelativeSpeed +1 = clockwise, -1 = counterclockwise
void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	UE_LOG(LogTemp, Warning, TEXT("Rotation : %f"), Rotation)
	SetRelativeRotation(FRotator(0, Rotation, 0));

}

