// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoordinateActor.generated.h"

UCLASS()
class COORDINATEPROJECT_API ACoordinateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoordinateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	FVector2D CurrentPosition = FVector2D(.0f,.0f);
	TArray<FVector2D> Path;
	int32 EventCount = 0;
	float TotalDistance = 0;


	void Move();
	float CalculateDistace(FVector2D A, FVector2D B);
	void TriggerEventWithProbability();

};
