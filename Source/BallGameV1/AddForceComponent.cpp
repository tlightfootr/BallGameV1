// Fill out your copyright notice in the Description page of Project Settings.


#include "AddForceComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"
#include "Math/Rotator.h"

// Sets default values for this component's properties
UAddForceComponent::UAddForceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAddForceComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
	// Getting static mesh
	StaticMeshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	// Getting camera arm
	CameraArmComponent = GetOwner()->FindComponentByClass<USpringArmComponent>();
	

}


// Called every frame
void UAddForceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Getting velocity components as a vector
	BallVelocityComponents = GetOwner()->GetVelocity();
}

void UAddForceComponent::SetupInputComponent()
{
	// Getting input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		// Binding functions to keypresses
		InputComponent->BindAxis(TEXT("MoveForward"), this, &UAddForceComponent::MoveForward);
		InputComponent->BindAxis(TEXT("MoveRight"), this, &UAddForceComponent::MoveRight);
	}
}

// Move forward function, Called by input component every tick
void UAddForceComponent::MoveForward(float Value)
{
	// Checking if ball has reached max velocity
	if (BallVelocityComponents.X < MaxSpeed)
	{
		// Checking if force applied is in opposite direction to movement of ball to apply greater force
		if (BallVelocityComponents.X > 0 && Value < 0)
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector ForwardVector(Value * ForceApplied * 1000 * StoppingMultiplier, 0.f, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			ForwardVector = RotateForceVector.RotateVector(ForwardVector);
			StaticMeshComponent->AddForce(ForwardVector);
		}
		else if (BallVelocityComponents.X < 0 && Value > 0)
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector ForwardVector(Value * ForceApplied * 1000 * StoppingMultiplier, 0.f, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			ForwardVector = RotateForceVector.RotateVector(ForwardVector);
			StaticMeshComponent->AddForce(ForwardVector);
		}
		else
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector ForwardVector(Value * ForceApplied * 1000, 0.f, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			ForwardVector = RotateForceVector.RotateVector(ForwardVector);
			StaticMeshComponent->AddForce(ForwardVector);
		}
	}
}

// Move Right function, Called by input component every tick
void UAddForceComponent::MoveRight(float Value)
{
	// Checking if ball has reached max velocity
	if (BallVelocityComponents.Y < MaxSpeed)
	{
		// Checking if force applied is in opposite direction to movement of ball to apply greater force
		if (BallVelocityComponents.Y > 0 && Value < 0)
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector RightVector(0.f, Value * ForceApplied * 1000 * StoppingMultiplier, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			RightVector = RotateForceVector.RotateVector(RightVector);
			StaticMeshComponent->AddForce(RightVector);
		}
		else if (BallVelocityComponents.Y < 0 && Value > 0)
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector RightVector(0.f, Value * ForceApplied * 1000 * StoppingMultiplier, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			RightVector = RotateForceVector.RotateVector(RightVector);
			StaticMeshComponent->AddForce(RightVector);
		}
		else
		{
			// Applying force to ball, Value determines direction (either 1 or -1)
			FVector RightVector(0.f, Value * ForceApplied * 1000, 0.f);
			// Getting rotation of camera arm
			FRotator RotateForceVector = CameraArmComponent->GetComponentRotation();
			// Rotating force vector by the camera arm
			RightVector = RotateForceVector.RotateVector(RightVector);
			StaticMeshComponent->AddForce(RightVector);
		}
	}
}

