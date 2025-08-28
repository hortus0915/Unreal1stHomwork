// Fill out your copyright notice in the Description page of Project Settings.


#include "CoordinateActor.h"

// Sets default values
ACoordinateActor::ACoordinateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACoordinateActor::BeginPlay()
{
	Super::BeginPlay();
	
	Path.Add(CurrentPosition);
	Move();

	UE_LOG(LogTemp, Warning, TEXT("TotalDistance: %f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("EventCount: %d"), EventCount);
}

void ACoordinateActor::Move()
{
	for (int i = 0; i < 10; i++)
	{
		int32 moveX = FMath::RandRange(0, 1);
		int32 moveY = FMath::RandRange(0, 1);

		FVector2D prevPosition = CurrentPosition;
		CurrentPosition.X += moveX;
		CurrentPosition.Y += moveY;
		Path.Add(CurrentPosition);

		float MoveDistance = CalculateDistace(prevPosition, CurrentPosition);
		TotalDistance += MoveDistance;

		UE_LOG(LogTemp, Warning, TEXT("Move %d - Current Coordinate : (%.0f, %.0f)"),
			i + 1, CurrentPosition.X, CurrentPosition.Y);
		UE_LOG(LogTemp, Warning, TEXT("Move Distance: %.2f"), MoveDistance);

		TriggerEventWithProbability();

	}
}

float ACoordinateActor::CalculateDistace(FVector2D A, FVector2D B)
{
	float dx = A.X - B.X;
	float dy = A.Y - B.Y;

	return FMath::Sqrt(dx * dx + dy * dy);
}

void ACoordinateActor::TriggerEventWithProbability()
{
	bool bIsEvent = FMath::RandBool();

	if (bIsEvent)
	{
		UE_LOG(LogTemp, Warning, TEXT(" Event Triggered"));
		EventCount++;
	}

}



