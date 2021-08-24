// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateBlade.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"

// Sets default values for this component's properties
URotateBlade::URotateBlade()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateBlade::BeginPlay()
{
	Super::BeginPlay();

	SawBlade = Cast<UArrowComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("SawBlade")));
	
	// ...
	
}

// Called every frame
void URotateBlade::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SawBlade)
	{
		FRotator CurrentRotation = SawBlade->GetComponentRotation();
		CurrentRotation.Roll += 10;
		SawBlade->SetWorldRotation(CurrentRotation);
	}
	// ...
}

