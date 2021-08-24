// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCamera.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
UMoveCamera::UMoveCamera()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveCamera::BeginPlay()
{
	Super::BeginPlay();
	
	// Getting static mesh and camera arm component
	StaticMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	CameraArmComponent = GetOwner()->FindComponentByClass<USpringArmComponent>();
	SetupInputComponent();
}

void UMoveCamera::SetupInputComponent()
{
	// Getting input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		// Binding functions to keypresses
		InputComponent->BindAction(TEXT("RotateCameraCW"), IE_Pressed, this, &UMoveCamera::RotateCameraCW);
		InputComponent->BindAction(TEXT("RotateCameraCCW"), IE_Pressed, this, &UMoveCamera::RotateCameraCCW);
	}
}

// Called every frame
void UMoveCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Setting location of the camera arm to the ball every frame 
	CameraArmComponent->SetWorldLocation(StaticMesh->GetComponentLocation());

}

// Run when right arrow key is pressed
void UMoveCamera::RotateCameraCW()
{
	// Getting camera arm and adding 90 degrees to yaw component
	FRotator CurrentRotation = CameraArmComponent->GetComponentRotation();
	CurrentRotation.Yaw += 90;
	// Setting new rotation to camera arm
	CameraArmComponent->SetWorldRotation(CurrentRotation);
	UE_LOG(LogTemp, Error, TEXT("%f"), CurrentRotation.Yaw);
}

// Run when left arrow key is pressed
void UMoveCamera::RotateCameraCCW()
{
	// Getting camera arm and subtracting 90 degrees to yaw component
	FRotator CurrentRotation = CameraArmComponent->GetComponentRotation();
	CurrentRotation.Yaw -= 90;
	// Setting new rotation to camera arm
	CameraArmComponent->SetWorldRotation(CurrentRotation);
	UE_LOG(LogTemp, Error, TEXT("%f"), CurrentRotation.Yaw);
}

