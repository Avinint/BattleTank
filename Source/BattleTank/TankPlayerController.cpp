#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}

// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto Possessed = GetControlledTank();
	if (!Possessed) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank controlled"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn is %s"), *Possessed->GetName());
	}
	
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController begin play"));
}