// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//set rotator with aim direction
	//rotate barrel according to z
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevate at %f m/s"), DegreesPerSecond);
}


