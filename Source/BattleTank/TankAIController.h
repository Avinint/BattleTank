// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	ATank * GetControlledTank() const;
	ATank * GetPlayerTank() const;
};
