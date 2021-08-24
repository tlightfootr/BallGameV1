// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveSpear.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"

// Sets default values for this component's properties
UMoveSpear::UMoveSpear()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveSpear::BeginPlay()
{
	Super::BeginPlay();

	Spear = Cast<UArrowComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Spear")));
	InitialLocation = Spear->GetComponentLocation();
	// ...
	
}


// Called every frame
void UMoveSpear::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (IsExtending)
	{
		FVector CurrentLocation = Spear->GetComponentLocation();
		CurrentLocation.Y = FMath::FInterpConstantTo(CurrentLocation.Y, InitialLocation.Y + FinalExtension, DeltaTime, 1200.f);
		Spear->SetWorldLocation(CurrentLocation);

		if (CurrentLocation.Y == InitialLocation.Y + FinalExtension)
		{
			IsExtending = false;
		}
	}
	else
	{
		FVector CurrentLocation = Spear->GetComponentLocation();
		CurrentLocation.Y = FMath::FInterpConstantTo(CurrentLocation.Y, InitialLocation.Y, DeltaTime, 250.f);
		Spear->SetWorldLocation(CurrentLocation);

		if (CurrentLocation.Y == InitialLocation.Y)
		{
			IsExtending = true;
		}
	}
	// ...
}

